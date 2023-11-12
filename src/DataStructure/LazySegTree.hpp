#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

namespace lib {
template <class T, class E>
class LazySegTree {
   public:
    LazySegTree(int N, std::function<T(T, T)> operation, T identity_t,
                std::function<T(E, T)> mapping,
                std::function<E(E, E)> composition, E identity_e)
        : LazySegTree(std::vector<T>(N, identity_t), operation, identity_t,
                      mapping, composition, identity_e) {}

    LazySegTree(std::vector<T>& vec, std::function<T(T, T)> operation,
                T identity_t, std::function<T(E, T)> mapping,
                std::function<E(E, E)> composition, E identity_e)
        : _N(int(vec.size())),
          operation(operation),
          identity_t(identity_t),
          mapping(mapping),
          composition(composition),
          identity_e(identity_e) {
        int log = 0;
        while ((1U << log) < (unsigned int)(_N)) {
            log++;
        }
        this->log = log;
        this->size = 1 << log;
        node = std::vector<T>(size << 1, identity_t);
        lazy = std::vector<E>(size, identity_e);
        for (int i = 0; i < _N; i++) {
            node[size + i] = vec[i];
        }
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int idx, T value) {
        assert(0 <= idx && idx < _N);
        idx += size;
        for (int i = log; i >= 1; i--) {
            execute(idx >> i);
        }
        node[idx] = value;
        for (int i = 1; i <= log; i++) {
            update(idx >> i);
        }
    }

    T get(int idx) {
        assert(0 <= idx && idx < _N);
        idx += size;
        for (int i = log; i >= 1; i--) {
            execute(idx >> i);
        }
        return node[idx];
    }

    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _N);
        if (l == r) {
            return identity_t;
        }
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            // iより下桁が全て0
            if ((l >> i) << i != l) {
                execute(l >> i);
            }
            if ((r >> i) << i != r) {
                execute(r >> i);
            }
        }

        T vl = identity_t, vr = identity_t;
        while (l < r) {
            if (l & 1) {
                vl = operation(vl, node[l++]);
            }
            if (r & 1) {
                vr = operation(node[--r], vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return operation(vl, vr);
    }

    T all_prod() { return node[1]; }

    void apply(int idx, E vf) {
        assert(0 <= idx && idx < _N);
        idx += size;
        for (int i = log; i >= 1; i--) {
            execute(idx >> i);
        }
        node[idx] = mapping(vf, node[idx]);
        for (int i = 1; i <= log; i++) {
            update(idx >> i);
        }
    }

    void apply(int l, int r, E vf) {
        assert(0 <= l && l <= r && r <= _N);
        if (l == r) {
            return;
        }

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                execute(l >> i);
            }
            if (((r >> i) << i) != r) {
                execute((r - 1) >> i);
            }
        }

        int l2 = l, r2 = r;
        while (l < r) {
            if (l & 1) {
                all_apply(l++, vf);
            }
            if (r & 1) {
                all_apply(--r, vf);
            }
            l >>= 1;
            r >>= 1;
        }
        l = l2;
        r = r2;

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) {
                update(l >> i);
            }
            if (((r >> i) << i) != r) {
                update((r - 1) >> i);
            }
        }
    }

    int max_right(int l, bool (*f)(T)) {
        assert(0 <= l && l <= _N);
        assert(f(identity_t));
        if (l == _N) return _N;
        l += size;
        for (int i = log; i >= 1; i--) {
            execute(l >> i);
        }
        T value = identity_t;
        do {
            while (!(l & 1)) {
                l >>= 1;
            }
            if (!f(operation(value, node[l]))) {
                while (l < size) {
                    execute(l);
                    l <<= 1;
                    if (f(operation(value, node[l]))) {
                        value = operation(value, node[l++]);
                    }
                }
                return l - size;
            }
            value = operation(value, node[l++]);
        } while ((l & -l) != l);
        return _N;
    }

    int min_left(int r, bool (*f)(T)) {
        assert(0 <= r && r <= _N);
        assert(f(identity_t));

        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) {
            execute((r - 1) >> i);
        }
        T value = identity_t;
        do {
            r--;
            while (r > 1 && !(r & 1)) {
                r >>= 1;
            }

            if (!f(operation(node[r], value))) {
                while (r < size) {
                    execute(r);
                    r = (r << 1) + 1;
                    if (f(operation(node[r], value))) {
                        value = operation(node[r--], value);
                    }
                }
                return r + 1 - size;
            }
            value = operation(node[r], value);
        } while ((r & -r) != r);
        return 0;
    }

   private:
    const int _N;
    int size, log;
    const T identity_t;  // 二項演算operationの単位元
    const E identity_e;  // 二項演算compositionの単位元
    const std::function<T(T, T)> operation;
    const std::function<T(E, T)> mapping;  // E×Tの写像
    const std::function<E(E, E)> composition;
    std::vector<T> node;
    std::vector<E> lazy;
    void update(int idx) {
        node[idx] = operation(node[idx << 1], node[(idx << 1) | 1]);
    }
    void all_apply(int idx, E vf) {
        node[idx] = mapping(vf, node[idx]);
        if (idx < size) {
            lazy[idx] = composition(vf, lazy[idx]);
        }
    }
    void execute(int idx) {
        all_apply((idx << 1), lazy[idx]);
        all_apply((idx << 1) + 1, lazy[idx]);
        lazy[idx] = identity_e;
    }
};
}  // namespace lib
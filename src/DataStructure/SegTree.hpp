#pragma once

#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

namespace lib{
    template <class T>
    class SegTree {
    private:
        const int _N;
        int log, size;
        const std::function<T(T, T)> operation;  // 演算
        const T identity;                        // 単位元
        std::vector<T> node;

        void update(int idx) {
            node[idx] = operation(node[idx << 1], node[(idx << 1) | 1]);
        }

    public:
        SegTree(int N, std::function<T(T, T)> operation, T identity)
            : SegTree(std::vector<T>(N, identity), operation, identity) {}

        SegTree(const std::vector<T>& vec, std::function<T(T, T)> operation,
                T identity)
            : _N(int(vec.size())), operation(operation), identity(identity) {
            int log = 0;
            while ((1U << log) < (unsigned int)(_N)) {
                log++;
            }
            this->log = log;
            this->size = 1 << log;
            node = std::vector<T>(size << 1, identity);
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
            node[idx] = value;
            for (int i = 1; i <= log; i++) {
                update(idx >> i);
            }
        }

        T get(int idx) {
            assert(0 <= idx && idx < _N);
            return node[idx + size];
        }

        T prod(int l, int r) {
            assert(0 <= l && l <= r && r <= _N);
            if (l == r) {
                return identity;
            }
            T vl = identity, vr = identity;
            l += size;
            r += size;
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

        int max_right(int l, bool (*f)(T)) {
            assert(0 <= l && l <= _N);
            assert(f(identity));
            if (l == _N) return _N;
            l += size;
            T value = identity;
            do {
                while (!(l & 1)) {
                    l >>= 1;
                }
                if (!f(operation(value, node[l]))) {
                    while (l < size) {
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
            assert(f(identity));

            if (r == 0) return 0;
            r += size;
            T value = identity;
            do {
                r--;
                while (r > 1 && !(r & 1)) {
                    r >>= 1;
                }

                if (!f(operation(node[r], value))) {
                    while (r < size) {
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
    };
}
---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/LazySegTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: src/Modint/StaticModint.hpp
    title: src/Modint/StaticModint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#line 1 \"src/DataStructure/LazySegTree.hpp\"\
    \n#include <cassert>\n#include <functional>\n#line 5 \"src/DataStructure/LazySegTree.hpp\"\
    \n\nnamespace lib {\ntemplate <class T, class E>\nclass LazySegTree {\n   public:\n\
    \    LazySegTree(int N, std::function<T(T, T)> operation, T identity_t,\n    \
    \            std::function<T(E, T)> mapping,\n                std::function<E(E,\
    \ E)> composition, E identity_e)\n        : LazySegTree(std::vector<T>(N, identity_t),\
    \ operation, identity_t,\n                      mapping, composition, identity_e)\
    \ {}\n\n    LazySegTree(std::vector<T>& vec, std::function<T(T, T)> operation,\n\
    \                T identity_t, std::function<T(E, T)> mapping,\n             \
    \   std::function<E(E, E)> composition, E identity_e)\n        : _N(int(vec.size())),\n\
    \          operation(operation),\n          identity_t(identity_t),\n        \
    \  mapping(mapping),\n          composition(composition),\n          identity_e(identity_e)\
    \ {\n        int log = 0;\n        while ((1U << log) < (unsigned int)(_N)) {\n\
    \            log++;\n        }\n        this->log = log;\n        this->size =\
    \ 1 << log;\n        node = std::vector<T>(size << 1, identity_t);\n        lazy\
    \ = std::vector<E>(size, identity_e);\n        for (int i = 0; i < _N; i++) {\n\
    \            node[size + i] = vec[i];\n        }\n        for (int i = size -\
    \ 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ idx, T value) {\n        assert(0 <= idx && idx < _N);\n        idx += size;\n\
    \        for (int i = log; i >= 1; i--) {\n            execute(idx >> i);\n  \
    \      }\n        node[idx] = value;\n        for (int i = 1; i <= log; i++) {\n\
    \            update(idx >> i);\n        }\n    }\n\n    T get(int idx) {\n   \
    \     assert(0 <= idx && idx < _N);\n        idx += size;\n        for (int i\
    \ = log; i >= 1; i--) {\n            execute(idx >> i);\n        }\n        return\
    \ node[idx];\n    }\n\n    T prod(int l, int r) {\n        assert(0 <= l && l\
    \ <= r && r <= _N);\n        if (l == r) {\n            return identity_t;\n \
    \       }\n        l += size;\n        r += size;\n        for (int i = log; i\
    \ >= 1; i--) {\n            // i\u3088\u308A\u4E0B\u6841\u304C\u5168\u30660\n\
    \            if ((l >> i) << i != l) {\n                execute(l >> i);\n   \
    \         }\n            if ((r >> i) << i != r) {\n                execute(r\
    \ >> i);\n            }\n        }\n\n        T vl = identity_t, vr = identity_t;\n\
    \        while (l < r) {\n            if (l & 1) {\n                vl = operation(vl,\
    \ node[l++]);\n            }\n            if (r & 1) {\n                vr = operation(node[--r],\
    \ vr);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return operation(vl, vr);\n    }\n\n    T all_prod() { return node[1];\
    \ }\n\n    void apply(int idx, E vf) {\n        assert(0 <= idx && idx < _N);\n\
    \        idx += size;\n        for (int i = log; i >= 1; i--) {\n            execute(idx\
    \ >> i);\n        }\n        node[idx] = mapping(vf, node[idx]);\n        for\
    \ (int i = 1; i <= log; i++) {\n            update(idx >> i);\n        }\n   \
    \ }\n\n    void apply(int l, int r, E vf) {\n        assert(0 <= l && l <= r &&\
    \ r <= _N);\n        if (l == r) {\n            return;\n        }\n\n       \
    \ l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--) {\n\
    \            if (((l >> i) << i) != l) {\n                execute(l >> i);\n \
    \           }\n            if (((r >> i) << i) != r) {\n                execute((r\
    \ - 1) >> i);\n            }\n        }\n\n        int l2 = l, r2 = r;\n     \
    \   while (l < r) {\n            if (l & 1) {\n                all_apply(l++,\
    \ vf);\n            }\n            if (r & 1) {\n                all_apply(--r,\
    \ vf);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        l = l2;\n        r = r2;\n\n        for (int i = 1; i <= log; i++) {\n\
    \            if (((l >> i) << i) != l) {\n                update(l >> i);\n  \
    \          }\n            if (((r >> i) << i) != r) {\n                update((r\
    \ - 1) >> i);\n            }\n        }\n    }\n\n    int max_right(int l, bool\
    \ (*f)(T)) {\n        assert(0 <= l && l <= _N);\n        assert(f(identity_t));\n\
    \        if (l == _N) return _N;\n        l += size;\n        for (int i = log;\
    \ i >= 1; i--) {\n            execute(l >> i);\n        }\n        T value = identity_t;\n\
    \        do {\n            while (!(l & 1)) {\n                l >>= 1;\n    \
    \        }\n            if (!f(operation(value, node[l]))) {\n               \
    \ while (l < size) {\n                    execute(l);\n                    l <<=\
    \ 1;\n                    if (f(operation(value, node[l]))) {\n              \
    \          value = operation(value, node[l++]);\n                    }\n     \
    \           }\n                return l - size;\n            }\n            value\
    \ = operation(value, node[l++]);\n        } while ((l & -l) != l);\n        return\
    \ _N;\n    }\n\n    int min_left(int r, bool (*f)(T)) {\n        assert(0 <= r\
    \ && r <= _N);\n        assert(f(identity_t));\n\n        if (r == 0) return 0;\n\
    \        r += size;\n        for (int i = log; i >= 1; i--) {\n            execute((r\
    \ - 1) >> i);\n        }\n        T value = identity_t;\n        do {\n      \
    \      r--;\n            while (r > 1 && !(r & 1)) {\n                r >>= 1;\n\
    \            }\n\n            if (!f(operation(node[r], value))) {\n         \
    \       while (r < size) {\n                    execute(r);\n                \
    \    r = (r << 1) + 1;\n                    if (f(operation(node[r], value)))\
    \ {\n                        value = operation(node[r--], value);\n          \
    \          }\n                }\n                return r + 1 - size;\n      \
    \      }\n            value = operation(node[r], value);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n   private:\n    const int _N;\n \
    \   int size, log;\n    const T identity_t;  // \u4E8C\u9805\u6F14\u7B97operation\u306E\
    \u5358\u4F4D\u5143\n    const E identity_e;  // \u4E8C\u9805\u6F14\u7B97composition\u306E\
    \u5358\u4F4D\u5143\n    const std::function<T(T, T)> operation;\n    const std::function<T(E,\
    \ T)> mapping;  // E\xD7T\u306E\u5199\u50CF\n    const std::function<E(E, E)>\
    \ composition;\n    std::vector<T> node;\n    std::vector<E> lazy;\n    void update(int\
    \ idx) {\n        node[idx] = operation(node[idx << 1], node[(idx << 1) | 1]);\n\
    \    }\n    void all_apply(int idx, E vf) {\n        node[idx] = mapping(vf, node[idx]);\n\
    \        if (idx < size) {\n            lazy[idx] = composition(vf, lazy[idx]);\n\
    \        }\n    }\n    void execute(int idx) {\n        all_apply((idx << 1),\
    \ lazy[idx]);\n        all_apply((idx << 1) + 1, lazy[idx]);\n        lazy[idx]\
    \ = identity_e;\n    }\n};\n}  // namespace lib\n#line 2 \"src/Modint/StaticModint.hpp\"\
    \n#include <cmath>\n#include <cstdint>\n#line 5 \"src/Modint/StaticModint.hpp\"\
    \n#include <ostream>\n\nnamespace lib {\ntemplate <std::uint_fast64_t mod>\nclass\
    \ StaticModint {\n   public:\n    std::uint_fast64_t _value;\n\n    StaticModint(const\
    \ long long value = 0) {\n        static_assert(mod > 0);\n        _value = ((std::abs(value)\
    \ / mod + 1) * mod + value) % mod;\n    }\n    std::uint_fast64_t value() { return\
    \ _value; }\n\n    StaticModint pow(long long N) {\n        StaticModint x = *this,\
    \ ret = 1;\n        if (N < 0) {\n            x = inv();\n            N = -N;\n\
    \        }\n\n        while (N) {\n            if (N & 1) {\n                ret\
    \ += x;\n            }\n            x *= x;\n            N >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    StaticModint inv() const { return pow(mod -\
    \ 2); }\n\n    StaticModint operator+(const StaticModint& rhs) {\n        return\
    \ StaticModint(*this) += rhs;\n    }\n    StaticModint operator-(const StaticModint&\
    \ rhs) {\n        return StaticModint(*this) -= rhs;\n    }\n    StaticModint\
    \ operator*(const StaticModint& rhs) {\n        return StaticModint(*this) *=\
    \ rhs;\n    }\n    StaticModint operator/(const StaticModint& rhs) {\n       \
    \ return StaticModint(*this) /= rhs;\n    }\n    StaticModint& operator+=(const\
    \ StaticModint& rhs) {\n        _value += rhs._value;\n        if (_value >= mod)\
    \ {\n            _value -= mod;\n        }\n        return *this;\n    }\n   \
    \ StaticModint& operator-=(const StaticModint& rhs) {\n        if (_value < rhs._value)\
    \ {\n            _value += mod;\n        }\n        _value -= rhs._value;\n  \
    \      return *this;\n    }\n    StaticModint& operator*=(const StaticModint&\
    \ rhs) {\n        _value = _value * rhs._value % mod;\n        return *this;\n\
    \    }\n    StaticModint& operator/=(StaticModint& rhs) {\n        *this *= rhs.inv();\n\
    \        return *this;\n    }\n    bool operator==(const StaticModint& rhs) {\
    \ return _value == rhs._value; }\n    bool operator!=(const StaticModint& rhs)\
    \ { return _value != rhs._value; }\n    StaticModint& operator++() {\n       \
    \ _value++;\n        if (_value == mod) {\n            _value = 0;\n        }\n\
    \    }\n    StaticModint& operator--() {\n        if (_value == 0) {\n       \
    \     _value = mod;\n        }\n        _value--;\n    }\n\n    std::ostream&\
    \ operator<<(std::ostream& os) {\n        os << _value;\n        return os;\n\
    \    }\n};\n}  // namespace lib\n#line 8 \"test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp\"\
    \n\nusing mint = lib::StaticModint<998244353>;\n\nint main() {\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    std::vector<std::pair<mint, mint>> A(N);\n    for\
    \ (int i = 0; i < N; i++) {\n        long long input;\n        std::cin >> input;\n\
    \        A[i] = std::make_pair(input, 1);\n    }\n    lib::LazySegTree<std::pair<mint,\
    \ mint>, std::pair<mint, mint>> seg(\n        A,\n        [](std::pair<mint, mint>\
    \ a,\n           std::pair<mint, mint> b) -> std::pair<mint, mint> {\n       \
    \     return std::make_pair(a.first + b.first, a.second + b.second);\n       \
    \ },\n        std::make_pair(0, 0),\n        [](std::pair<mint, mint> f,\n   \
    \        std::pair<mint, mint> a) -> std::pair<mint, mint> {\n            return\
    \ std::make_pair(f.first * a.first + f.second * a.second,\n                  \
    \                a.second);\n        },\n        [](std::pair<mint, mint> a,\n\
    \           std::pair<mint, mint> b) -> std::pair<mint, mint> {\n            return\
    \ std::make_pair(a.first * b.first,\n                                  a.first\
    \ * b.second + a.second);\n        },\n        std::make_pair(1, 0));\n\n    for\
    \ (int i = 0; i < Q; i++) {\n        int t;\n        std::cin >> t;\n        if\
    \ (t == 0) {\n            int l, r;\n            long long c, d;\n           \
    \ std::cin >> l >> r >> c >> d;\n            seg.apply(l, r, std::make_pair(c,\
    \ d));\n        } else {\n            int l, r;\n            std::cin >> l >>\
    \ r;\n            std::cout << seg.prod(l, r).first.value() << '\\n';\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/DataStructure/LazySegTree.hpp\"\
    \n#include \"../../src/Modint/StaticModint.hpp\"\n\nusing mint = lib::StaticModint<998244353>;\n\
    \nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::pair<mint,\
    \ mint>> A(N);\n    for (int i = 0; i < N; i++) {\n        long long input;\n\
    \        std::cin >> input;\n        A[i] = std::make_pair(input, 1);\n    }\n\
    \    lib::LazySegTree<std::pair<mint, mint>, std::pair<mint, mint>> seg(\n   \
    \     A,\n        [](std::pair<mint, mint> a,\n           std::pair<mint, mint>\
    \ b) -> std::pair<mint, mint> {\n            return std::make_pair(a.first + b.first,\
    \ a.second + b.second);\n        },\n        std::make_pair(0, 0),\n        [](std::pair<mint,\
    \ mint> f,\n           std::pair<mint, mint> a) -> std::pair<mint, mint> {\n \
    \           return std::make_pair(f.first * a.first + f.second * a.second,\n \
    \                                 a.second);\n        },\n        [](std::pair<mint,\
    \ mint> a,\n           std::pair<mint, mint> b) -> std::pair<mint, mint> {\n \
    \           return std::make_pair(a.first * b.first,\n                       \
    \           a.first * b.second + a.second);\n        },\n        std::make_pair(1,\
    \ 0));\n\n    for (int i = 0; i < Q; i++) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            int l, r;\n            long long c,\
    \ d;\n            std::cin >> l >> r >> c >> d;\n            seg.apply(l, r, std::make_pair(c,\
    \ d));\n        } else {\n            int l, r;\n            std::cin >> l >>\
    \ r;\n            std::cout << seg.prod(l, r).first.value() << '\\n';\n      \
    \  }\n    }\n}"
  dependsOn:
  - src/DataStructure/LazySegTree.hpp
  - src/Modint/StaticModint.hpp
  isVerificationFile: true
  path: test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 20:44:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp
- /verify/test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp.html
title: test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp
---

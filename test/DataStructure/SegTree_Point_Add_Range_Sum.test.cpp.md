---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegTree.hpp
    title: src/DataStructure/SegTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\n#line 2 \"src/DataStructure/SegTree.hpp\"\
    \n\n#include <cassert>\n#include <functional>\n#line 7 \"src/DataStructure/SegTree.hpp\"\
    \n\nnamespace lib{\n    template <class T>\n    class SegTree {\n    private:\n\
    \        const int _N;\n        int log, size;\n        const std::function<T(T,\
    \ T)> operation;  // \u6F14\u7B97\n        const T identity;                 \
    \       // \u5358\u4F4D\u5143\n        std::vector<T> node;\n\n        void update(int\
    \ idx) {\n            node[idx] = operation(node[idx << 1], node[(idx << 1) |\
    \ 1]);\n        }\n\n    public:\n        SegTree(int N, std::function<T(T, T)>\
    \ operation, T identity)\n            : SegTree(std::vector<T>(N, identity), operation,\
    \ identity) {}\n\n        SegTree(const std::vector<T>& vec, std::function<T(T,\
    \ T)> operation,\n                T identity)\n            : _N(int(vec.size())),\
    \ operation(operation), identity(identity) {\n            int log = 0;\n     \
    \       while ((1U << log) < (unsigned int)(_N)) {\n                log++;\n \
    \           }\n            this->log = log;\n            this->size = 1 << log;\n\
    \            node = std::vector<T>(size << 1, identity);\n            for (int\
    \ i = 0; i < _N; i++) {\n                node[size + i] = vec[i];\n          \
    \  }\n            for (int i = size - 1; i >= 1; i--) {\n                update(i);\n\
    \            }\n        }\n\n        void set(int idx, T value) {\n          \
    \  assert(0 <= idx && idx < _N);\n            idx += size;\n            node[idx]\
    \ = value;\n            for (int i = 1; i <= log; i++) {\n                update(idx\
    \ >> i);\n            }\n        }\n\n        T get(int idx) {\n            assert(0\
    \ <= idx && idx < _N);\n            return node[idx + size];\n        }\n\n  \
    \      T prod(int l, int r) {\n            assert(0 <= l && l <= r && r <= _N);\n\
    \            if (l == r) {\n                return identity;\n            }\n\
    \            T vl = identity, vr = identity;\n            l += size;\n       \
    \     r += size;\n            while (l < r) {\n                if (l & 1) {\n\
    \                    vl = operation(vl, node[l++]);\n                }\n     \
    \           if (r & 1) {\n                    vr = operation(node[--r], vr);\n\
    \                }\n                l >>= 1;\n                r >>= 1;\n     \
    \       }\n            return operation(vl, vr);\n        }\n\n        T all_prod()\
    \ { return node[1]; }\n\n        int max_right(int l, bool (*f)(T)) {\n      \
    \      assert(0 <= l && l <= _N);\n            assert(f(identity));\n        \
    \    if (l == _N) return _N;\n            l += size;\n            T value = identity;\n\
    \            do {\n                while (!(l & 1)) {\n                    l >>=\
    \ 1;\n                }\n                if (!f(operation(value, node[l]))) {\n\
    \                    while (l < size) {\n                        l <<= 1;\n  \
    \                      if (f(operation(value, node[l]))) {\n                 \
    \           value = operation(value, node[l++]);\n                        }\n\
    \                    }\n                    return l - size;\n               \
    \ }\n                value = operation(value, node[l++]);\n            } while\
    \ ((l & -l) != l);\n            return _N;\n        }\n\n        int min_left(int\
    \ r, bool (*f)(T)) {\n            assert(0 <= r && r <= _N);\n            assert(f(identity));\n\
    \n            if (r == 0) return 0;\n            r += size;\n            T value\
    \ = identity;\n            do {\n                r--;\n                while (r\
    \ > 1 && !(r & 1)) {\n                    r >>= 1;\n                }\n\n    \
    \            if (!f(operation(node[r], value))) {\n                    while (r\
    \ < size) {\n                        r = (r << 1) + 1;\n                     \
    \   if (f(operation(node[r], value))) {\n                            value = operation(node[r--],\
    \ value);\n                        }\n                    }\n                \
    \    return r + 1 - size;\n                }\n                value = operation(node[r],\
    \ value);\n            } while ((r & -r) != r);\n            return 0;\n     \
    \   }\n    };\n}\n#line 6 \"test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    \n    std::vector<long\
    \ long> A(N);\n    for(int i = 0;i < N;i++){\n        std::cin >> A[i];\n    }\n\
    \n    lib::SegTree<long long> seg(A, \n        [](long long a, long long b) ->\
    \ long long{return a + b;}, \n        0LL);\n\n    for(int i = 0;i < Q;i++){\n\
    \        long long t, l, r;\n        std::cin >> t >> l >> r;\n        if(t ==\
    \ 0){\n            seg.set(l, seg.get(l) + r);\n        }\n        if(t == 1){\n\
    \            std::cout << seg.prod(l, r) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n#include \"../../src/DataStructure/SegTree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    \n    std::vector<long\
    \ long> A(N);\n    for(int i = 0;i < N;i++){\n        std::cin >> A[i];\n    }\n\
    \n    lib::SegTree<long long> seg(A, \n        [](long long a, long long b) ->\
    \ long long{return a + b;}, \n        0LL);\n\n    for(int i = 0;i < Q;i++){\n\
    \        long long t, l, r;\n        std::cin >> t >> l >> r;\n        if(t ==\
    \ 0){\n            seg.set(l, seg.get(l) + r);\n        }\n        if(t == 1){\n\
    \            std::cout << seg.prod(l, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/DataStructure/SegTree.hpp
  isVerificationFile: true
  path: test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 00:32:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp
- /verify/test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp.html
title: test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp
---

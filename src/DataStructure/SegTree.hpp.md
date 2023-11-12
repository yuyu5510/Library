---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp
    title: test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegTree.hpp\"\n\n#include <cassert>\n\
    #include <functional>\n#include <iostream>\n#include <vector>\n\nnamespace lib{\n\
    \    template <class T>\n    class SegTree {\n    private:\n        const int\
    \ _N;\n        int log, size;\n        const std::function<T(T, T)> operation;\
    \  // \u6F14\u7B97\n        const T identity;                        // \u5358\
    \u4F4D\u5143\n        std::vector<T> node;\n\n        void update(int idx) {\n\
    \            node[idx] = operation(node[idx << 1], node[(idx << 1) | 1]);\n  \
    \      }\n\n    public:\n        SegTree(int N, std::function<T(T, T)> operation,\
    \ T identity)\n            : SegTree(std::vector<T>(N, identity), operation, identity)\
    \ {}\n\n        SegTree(const std::vector<T>& vec, std::function<T(T, T)> operation,\n\
    \                T identity)\n            : _N(int(vec.size())), operation(operation),\
    \ identity(identity) {\n            int log = 0;\n            while ((1U << log)\
    \ < (unsigned int)(_N)) {\n                log++;\n            }\n           \
    \ this->log = log;\n            this->size = 1 << log;\n            node = std::vector<T>(size\
    \ << 1, identity);\n            for (int i = 0; i < _N; i++) {\n             \
    \   node[size + i] = vec[i];\n            }\n            for (int i = size - 1;\
    \ i >= 1; i--) {\n                update(i);\n            }\n        }\n\n   \
    \     void set(int idx, T value) {\n            assert(0 <= idx && idx < _N);\n\
    \            idx += size;\n            node[idx] = value;\n            for (int\
    \ i = 1; i <= log; i++) {\n                update(idx >> i);\n            }\n\
    \        }\n\n        T get(int idx) {\n            assert(0 <= idx && idx < _N);\n\
    \            return node[idx + size];\n        }\n\n        T prod(int l, int\
    \ r) {\n            assert(0 <= l && l <= r && r <= _N);\n            if (l ==\
    \ r) {\n                return identity;\n            }\n            T vl = identity,\
    \ vr = identity;\n            l += size;\n            r += size;\n           \
    \ while (l < r) {\n                if (l & 1) {\n                    vl = operation(vl,\
    \ node[l++]);\n                }\n                if (r & 1) {\n             \
    \       vr = operation(node[--r], vr);\n                }\n                l >>=\
    \ 1;\n                r >>= 1;\n            }\n            return operation(vl,\
    \ vr);\n        }\n\n        T all_prod() { return node[1]; }\n\n        int max_right(int\
    \ l, bool (*f)(T)) {\n            assert(0 <= l && l <= _N);\n            assert(f(identity));\n\
    \            if (l == _N) return _N;\n            l += size;\n            T value\
    \ = identity;\n            do {\n                while (!(l & 1)) {\n        \
    \            l >>= 1;\n                }\n                if (!f(operation(value,\
    \ node[l]))) {\n                    while (l < size) {\n                     \
    \   l <<= 1;\n                        if (f(operation(value, node[l]))) {\n  \
    \                          value = operation(value, node[l++]);\n            \
    \            }\n                    }\n                    return l - size;\n\
    \                }\n                value = operation(value, node[l++]);\n   \
    \         } while ((l & -l) != l);\n            return _N;\n        }\n\n    \
    \    int min_left(int r, bool (*f)(T)) {\n            assert(0 <= r && r <= _N);\n\
    \            assert(f(identity));\n\n            if (r == 0) return 0;\n     \
    \       r += size;\n            T value = identity;\n            do {\n      \
    \          r--;\n                while (r > 1 && !(r & 1)) {\n               \
    \     r >>= 1;\n                }\n\n                if (!f(operation(node[r],\
    \ value))) {\n                    while (r < size) {\n                       \
    \ r = (r << 1) + 1;\n                        if (f(operation(node[r], value)))\
    \ {\n                            value = operation(node[r--], value);\n      \
    \                  }\n                    }\n                    return r + 1\
    \ - size;\n                }\n                value = operation(node[r], value);\n\
    \            } while ((r & -r) != r);\n            return 0;\n        }\n    };\n\
    }\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <vector>\n\nnamespace lib{\n    template <class T>\n    class SegTree\
    \ {\n    private:\n        const int _N;\n        int log, size;\n        const\
    \ std::function<T(T, T)> operation;  // \u6F14\u7B97\n        const T identity;\
    \                        // \u5358\u4F4D\u5143\n        std::vector<T> node;\n\
    \n        void update(int idx) {\n            node[idx] = operation(node[idx <<\
    \ 1], node[(idx << 1) | 1]);\n        }\n\n    public:\n        SegTree(int N,\
    \ std::function<T(T, T)> operation, T identity)\n            : SegTree(std::vector<T>(N,\
    \ identity), operation, identity) {}\n\n        SegTree(const std::vector<T>&\
    \ vec, std::function<T(T, T)> operation,\n                T identity)\n      \
    \      : _N(int(vec.size())), operation(operation), identity(identity) {\n   \
    \         int log = 0;\n            while ((1U << log) < (unsigned int)(_N)) {\n\
    \                log++;\n            }\n            this->log = log;\n       \
    \     this->size = 1 << log;\n            node = std::vector<T>(size << 1, identity);\n\
    \            for (int i = 0; i < _N; i++) {\n                node[size + i] =\
    \ vec[i];\n            }\n            for (int i = size - 1; i >= 1; i--) {\n\
    \                update(i);\n            }\n        }\n\n        void set(int\
    \ idx, T value) {\n            assert(0 <= idx && idx < _N);\n            idx\
    \ += size;\n            node[idx] = value;\n            for (int i = 1; i <= log;\
    \ i++) {\n                update(idx >> i);\n            }\n        }\n\n    \
    \    T get(int idx) {\n            assert(0 <= idx && idx < _N);\n           \
    \ return node[idx + size];\n        }\n\n        T prod(int l, int r) {\n    \
    \        assert(0 <= l && l <= r && r <= _N);\n            if (l == r) {\n   \
    \             return identity;\n            }\n            T vl = identity, vr\
    \ = identity;\n            l += size;\n            r += size;\n            while\
    \ (l < r) {\n                if (l & 1) {\n                    vl = operation(vl,\
    \ node[l++]);\n                }\n                if (r & 1) {\n             \
    \       vr = operation(node[--r], vr);\n                }\n                l >>=\
    \ 1;\n                r >>= 1;\n            }\n            return operation(vl,\
    \ vr);\n        }\n\n        T all_prod() { return node[1]; }\n\n        int max_right(int\
    \ l, bool (*f)(T)) {\n            assert(0 <= l && l <= _N);\n            assert(f(identity));\n\
    \            if (l == _N) return _N;\n            l += size;\n            T value\
    \ = identity;\n            do {\n                while (!(l & 1)) {\n        \
    \            l >>= 1;\n                }\n                if (!f(operation(value,\
    \ node[l]))) {\n                    while (l < size) {\n                     \
    \   l <<= 1;\n                        if (f(operation(value, node[l]))) {\n  \
    \                          value = operation(value, node[l++]);\n            \
    \            }\n                    }\n                    return l - size;\n\
    \                }\n                value = operation(value, node[l++]);\n   \
    \         } while ((l & -l) != l);\n            return _N;\n        }\n\n    \
    \    int min_left(int r, bool (*f)(T)) {\n            assert(0 <= r && r <= _N);\n\
    \            assert(f(identity));\n\n            if (r == 0) return 0;\n     \
    \       r += size;\n            T value = identity;\n            do {\n      \
    \          r--;\n                while (r > 1 && !(r & 1)) {\n               \
    \     r >>= 1;\n                }\n\n                if (!f(operation(node[r],\
    \ value))) {\n                    while (r < size) {\n                       \
    \ r = (r << 1) + 1;\n                        if (f(operation(node[r], value)))\
    \ {\n                            value = operation(node[r--], value);\n      \
    \                  }\n                    }\n                    return r + 1\
    \ - size;\n                }\n                value = operation(node[r], value);\n\
    \            } while ((r & -r) != r);\n            return 0;\n        }\n    };\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegTree.hpp
  requiredBy: []
  timestamp: '2023-11-12 00:32:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DataStructure/SegTree_Point_Add_Range_Sum.test.cpp
documentation_of: src/DataStructure/SegTree.hpp
layout: document
title: Segment Tree
---

# segment tree

モノイドであるものに対し使用できるデータ構造です。\
モノイドとはひとつの二項演算と単位元をもつ代数的構造で、
- 結合律 $(a ・ b) ・ c = a ・ (b ・ c)$
- 単位元が存在する ($e ・ a = a ・ e = a$)
以下の2つの条件を満たすものです。

二項演算の計算量が $O(1)$ である時、
- 要素の $1$ 点更新
- ある区間 $[l, r)$ に対して演算を適用した結果の取得

を $O(logN)$ で行うことができます。

二項演算の計算量が $O(f)$ である時は、以下の計算量に $O(f)$ がかかります。

## コンストラクタ
1. `SegTree<T> (int N, std::function<T(T, T)> operation, T identity)`
2. `SegTree(const std::vector<T>& vec, std::function<T(T, T)> operation, T identity)`

- 型 T
- $T \times T \to T$ の二項演算 operation
- 単位元 identity
が必要です。

1.の形式では長さ $N$ の区間として、単位元で初期化されます。\
2.の形式では渡された vector の大きさの区間として、 vector の中の値で初期化されます\

### 計算量
$O(N)$




## set(int idx, T value)
idxの場所にvalueを代入する。
### 計算量
$O(logN)$

## get(int idx)
idxの場所の要素を取得する。
### 計算量
$O(1)$

## prod(int l, int r)
$[l, r)$ の区間の全ての要素に対して、コンストラクタに渡した演算を行った結果を返す。
### 計算量
$O(logN)$

## all_prod()
全ての区間に対してコンストラクタに渡した演算を行う。
### 計算量
$O(1)$
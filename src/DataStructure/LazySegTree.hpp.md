---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp
    title: test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/DataStructure/LazySegTree.hpp\"\n#include <cassert>\n\
    #include <functional>\n#include <iostream>\n#include <vector>\n\nnamespace lib\
    \ {\ntemplate <class T, class E>\nclass LazySegTree {\n   public:\n    LazySegTree(int\
    \ N, std::function<T(T, T)> operation, T identity_t,\n                std::function<T(E,\
    \ T)> mapping,\n                std::function<E(E, E)> composition, E identity_e)\n\
    \        : LazySegTree(std::vector<T>(N, identity_t), operation, identity_t,\n\
    \                      mapping, composition, identity_e) {}\n\n    LazySegTree(std::vector<T>&\
    \ vec, std::function<T(T, T)> operation,\n                T identity_t, std::function<T(E,\
    \ T)> mapping,\n                std::function<E(E, E)> composition, E identity_e)\n\
    \        : _N(int(vec.size())),\n          operation(operation),\n          identity_t(identity_t),\n\
    \          mapping(mapping),\n          composition(composition),\n          identity_e(identity_e)\
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
    \ = identity_e;\n    }\n};\n}  // namespace lib\n"
  code: "#include <cassert>\n#include <functional>\n#include <iostream>\n#include\
    \ <vector>\n\nnamespace lib {\ntemplate <class T, class E>\nclass LazySegTree\
    \ {\n   public:\n    LazySegTree(int N, std::function<T(T, T)> operation, T identity_t,\n\
    \                std::function<T(E, T)> mapping,\n                std::function<E(E,\
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
    \ = identity_e;\n    }\n};\n}  // namespace lib"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LazySegTree.hpp
  requiredBy: []
  timestamp: '2023-11-12 20:44:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp
documentation_of: src/DataStructure/LazySegTree.hpp
layout: document
title: Lazy Segment Tree
---

# Lazy Segment Tree

モノイドであるものに対し使用できるデータ構造です。\
モノイドとはひとつの二項演算と単位元をもつ代数的構造で、
- 結合律 $(a ・ b) ・ c = a ・ (b ・ c)$
- 単位元が存在する ($e ・ a = a ・ e = a$)
以下の2つの条件を満たすものです。

また モノイド $T$ に対し $T$ から $T$ への写像の集合 $F$ であって、以下の条件を満たす写像が使用できます。
- 恒等写像が $F$ の中に存在する。 ($\forall x \in T, \exists id \in F \land id(x) = x$)
- 写像の合成について閉じている。 ($\forall f, g \in F,  f \circ g \in F$)
- 乗法的である。 ($\forall f \in F, x, y \in T,  f(x・y) = f(x) ・ f(y)$)


- ある区間 $[l, r)$ に対して $f \in F$ を作用
- ある区間 $[l, r)$ に対して要素の総積の取得
を $O(logN)$ で行うことができます。

以降の計算量は、写像および要素の積(二項演算)が　$O(1)$ でできると仮定しています。 $O(1)$ でない場合それだけの計算量がかかります。

## コンストラクタ
1.
```
LazySegTree<T, E> 
(
    int N, 
    std::function<T(T, T)> operation, 
    T identity_t, 
    std::function<T(E, T)> mapping ,
    std::function<E(E, E)>composition, 
    E identity_e>
)
```
2.
```
LazySegTree<T, E> 
(
    vector<T>& vec, 
    std::function<T(T, T)> operation, 
    T identity_t, 
    std::function<T(E, T)> mapping, 
    std::function<E(E, E)>composition, 
    E identity_e>
)
```

- モノイドの型 T
- 写像の型 E
- $T \times T \to T$ の二項演算 operation
- モノイドの単位元 identity_t
- $f(x)$ を返す写像 mapping
- $f \circ g$ の合成者像 composition
- 恒等写像 id
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

## apply(int idx, E vf)
idx の一点のみに対して写像 vf を適用
### 計算量
$O(log N)$

## apply(int l, int r, E vf)
$[l, r)$ に対して写像 vf を適用
### 計算量
$O(log N)$
---
title: Lazy Segment Tree
documentation_of: ./src/DataStructure/LazySegTree.hpp
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
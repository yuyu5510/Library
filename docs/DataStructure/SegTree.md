---
title: Segment Tree
documentation_of: ./src/DataStructure/SegTree.hpp
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
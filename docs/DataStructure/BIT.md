---
title: BIT
documentation_of: ./src/DataStructure/BIT.hpp
---

# BIT
要素数が $N$ の区間に対して
- 要素の $1$ 点更新
- 区間の要素の総和

を $O(log N)$ で求めることができるデータ構造です。

## コンストラクタ
`BIT<T> (int N)`

長さ $N$ で値が 0 の区間を生成します。

### 計算量
$O(N)$

## add(int p, T x)
区間 $p$ に $x$ を加算します。

### 計算量
$O(log N)$

## sum(int idx)
区間 $[0, idx)$ の総和を返します
### 計算量
$O(log N)$

## sum(int l, int r)
区間 $[l, r)$ の総和を返します
### 計算量
$O(log N)$
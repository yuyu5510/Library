---
title: Prime
documentation_of: ./src/Math/prime.hpp
---

# Prime
素数関連の関数をまとめたクラスです。

## is_prime
$2^64$ 未満の整数に対して素数かどうか高速に判定します。\
ミラーラビン法を用いています。

### 計算量
$O(logn)$


## factorize
$2^64$ 未満の整数に対して素因数分解を行います。\
ポラード・ローの素因数分解を用いています。１

### 計算量
$O(n^\frac{1}{4})$
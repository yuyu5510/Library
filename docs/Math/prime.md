---
title: Prime
documentation_of: ./src/Math/prime.hpp
---

# Prime
素数関連の関数をまとめたクラスです。

## is_prime(__int128_t n)
$2^64$ までの整数に対して素数かどうか高速に判定します。\
ミラーラビン法を用いています。

### 計算量
$O(logn)$


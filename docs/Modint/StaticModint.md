---
title: Static Modint
documentation_of: ./src/DataStructure/StaticModint.hpp
---

# Static Modint
法が静的に定まっているかつ、素数であるときにのみ使えます。
各種演算に対し自動でmodを取り、余りを計算してくれます。

演算 `+, -, *, /, +=, -=, *=, /=, ==, !=` に対応しています。

## コンストラクタ
`StaticModint<std::uint_fast64_t mod>(const long long value)`

mod は正の数かつ、素数かつ、定数でなければなりません。
valueには負の値でも入れることはできます。

## value()
std::uint_fast64_t 型の数を返します。
### 計算量
$O(1)$

## pow(long long N)
StaticModint の数を $N$ 乗します。
### 計算量
$O(log N)$

## inv()
逆元を返します。
### 計算量
$O(log(mod))$





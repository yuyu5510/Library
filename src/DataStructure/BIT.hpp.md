---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp
    title: test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/BIT.hpp\"\n\n#include <cassert>\n#include\
    \ <functional>\n#include <iostream>\n#include <vector>\n\nnamespace lib {\ntemplate\
    \ <class T>\nclass BIT {\n   public:\n    BIT(int N) : _N(N), _bit(_N) {}\n  \
    \  void add(int idx, T value) {\n        assert(0 <= idx && idx < _N);\n     \
    \   idx++;\n        while (idx <= _N) {\n            _bit[idx - 1] += value;\n\
    \            idx += idx & -idx;\n        }\n    }\n\n    T sum(int idx) {\n  \
    \      assert(0 <= idx && idx <= _N);\n        T value = 0;\n        while (idx\
    \ > 0) {\n            value += _bit[idx - 1];\n            idx -= idx & -idx;\n\
    \        }\n        return value;\n    }\n\n    T sum(int l, int r) {\n      \
    \  assert(0 <= l && l <= r && r <= _N);\n        return sum(r) - sum(l);\n   \
    \ }\n\n   private:\n    int _N;\n    std::vector<T> _bit;\n};\n}  // namespace\
    \ lib\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <vector>\n\nnamespace lib {\ntemplate <class T>\nclass BIT {\n   public:\n\
    \    BIT(int N) : _N(N), _bit(_N) {}\n    void add(int idx, T value) {\n     \
    \   assert(0 <= idx && idx < _N);\n        idx++;\n        while (idx <= _N) {\n\
    \            _bit[idx - 1] += value;\n            idx += idx & -idx;\n       \
    \ }\n    }\n\n    T sum(int idx) {\n        assert(0 <= idx && idx <= _N);\n \
    \       T value = 0;\n        while (idx > 0) {\n            value += _bit[idx\
    \ - 1];\n            idx -= idx & -idx;\n        }\n        return value;\n  \
    \  }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _N);\n\
    \        return sum(r) - sum(l);\n    }\n\n   private:\n    int _N;\n    std::vector<T>\
    \ _bit;\n};\n}  // namespace lib"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BIT.hpp
  requiredBy: []
  timestamp: '2023-11-12 21:52:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp
documentation_of: src/DataStructure/BIT.hpp
layout: document
title: BIT
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
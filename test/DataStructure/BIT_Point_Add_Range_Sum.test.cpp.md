---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/BIT.hpp
    title: BIT
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
  bundledCode: "#line 1 \"test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"src/DataStructure/BIT.hpp\"\n\n#include\
    \ <cassert>\n#include <functional>\n#line 7 \"src/DataStructure/BIT.hpp\"\n\n\
    namespace lib {\ntemplate <class T>\nclass BIT {\n   public:\n    BIT(int N) :\
    \ _N(N), _bit(_N) {}\n    void add(int idx, T value) {\n        assert(0 <= idx\
    \ && idx < _N);\n        idx++;\n        while (idx <= _N) {\n            _bit[idx\
    \ - 1] += value;\n            idx += idx & -idx;\n        }\n    }\n\n    T sum(int\
    \ idx) {\n        assert(0 <= idx && idx <= _N);\n        T value = 0;\n     \
    \   while (idx > 0) {\n            value += _bit[idx - 1];\n            idx -=\
    \ idx & -idx;\n        }\n        return value;\n    }\n\n    T sum(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= _N);\n        return sum(r) -\
    \ sum(l);\n    }\n\n   private:\n    int _N;\n    std::vector<T> _bit;\n};\n}\
    \  // namespace lib\n#line 7 \"test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n\n    std::vector<long\
    \ long> A(N);\n    lib::BIT<long long> bit(N);\n    for (int i = 0; i < N; i++)\
    \ {\n        std::cin >> A[i];\n        bit.add(i, A[i]);\n    }\n\n    for (int\
    \ i = 0; i < Q; i++) {\n        long long t, l, r;\n        std::cin >> t >> l\
    \ >> r;\n        if (t == 0) {\n            bit.add(l, r);\n        }\n      \
    \  if (t == 1) {\n            std::cout << bit.sum(l, r) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../../src/DataStructure/BIT.hpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n\n    std::vector<long\
    \ long> A(N);\n    lib::BIT<long long> bit(N);\n    for (int i = 0; i < N; i++)\
    \ {\n        std::cin >> A[i];\n        bit.add(i, A[i]);\n    }\n\n    for (int\
    \ i = 0; i < Q; i++) {\n        long long t, l, r;\n        std::cin >> t >> l\
    \ >> r;\n        if (t == 0) {\n            bit.add(l, r);\n        }\n      \
    \  if (t == 1) {\n            std::cout << bit.sum(l, r) << '\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - src/DataStructure/BIT.hpp
  isVerificationFile: true
  path: test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 21:52:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp
- /verify/test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp.html
title: test/DataStructure/BIT_Point_Add_Range_Sum.test.cpp
---

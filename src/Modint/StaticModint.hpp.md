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
  bundledCode: "#line 1 \"src/Modint/StaticModint.hpp\"\n#include <cassert>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <iostream>\n#include <ostream>\n\nnamespace\
    \ lib {\ntemplate <std::uint_fast64_t mod>\nclass StaticModint {\n   public:\n\
    \    std::uint_fast64_t _value;\n\n    StaticModint(const long long value = 0)\
    \ {\n        static_assert(mod > 0);\n        _value = ((std::abs(value) / mod\
    \ + 1) * mod + value) % mod;\n    }\n    std::uint_fast64_t value() { return _value;\
    \ }\n\n    StaticModint pow(long long N) {\n        StaticModint x = *this, ret\
    \ = 1;\n        if (N < 0) {\n            x = inv();\n            N = -N;\n  \
    \      }\n\n        while (N) {\n            if (N & 1) {\n                ret\
    \ += x;\n            }\n            x *= x;\n            N >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    StaticModint inv() const { return pow(mod -\
    \ 2); }\n\n    StaticModint operator+(const StaticModint& rhs) {\n        return\
    \ StaticModint(*this) += rhs;\n    }\n    StaticModint operator-(const StaticModint&\
    \ rhs) {\n        return StaticModint(*this) -= rhs;\n    }\n    StaticModint\
    \ operator*(const StaticModint& rhs) {\n        return StaticModint(*this) *=\
    \ rhs;\n    }\n    StaticModint operator/(const StaticModint& rhs) {\n       \
    \ return StaticModint(*this) /= rhs;\n    }\n    StaticModint& operator+=(const\
    \ StaticModint& rhs) {\n        _value += rhs._value;\n        if (_value >= mod)\
    \ {\n            _value -= mod;\n        }\n        return *this;\n    }\n   \
    \ StaticModint& operator-=(const StaticModint& rhs) {\n        if (_value < rhs._value)\
    \ {\n            _value += mod;\n        }\n        _value -= rhs._value;\n  \
    \      return *this;\n    }\n    StaticModint& operator*=(const StaticModint&\
    \ rhs) {\n        _value = _value * rhs._value % mod;\n        return *this;\n\
    \    }\n    StaticModint& operator/=(StaticModint& rhs) {\n        *this *= rhs.inv();\n\
    \        return *this;\n    }\n    bool operator==(const StaticModint& rhs) {\
    \ return _value == rhs._value; }\n    bool operator!=(const StaticModint& rhs)\
    \ { return _value != rhs._value; }\n    StaticModint& operator++() {\n       \
    \ _value++;\n        if (_value == mod) {\n            _value = 0;\n        }\n\
    \    }\n    StaticModint& operator--() {\n        if (_value == 0) {\n       \
    \     _value = mod;\n        }\n        _value--;\n    }\n\n    std::ostream&\
    \ operator<<(std::ostream& os) {\n        os << _value;\n        return os;\n\
    \    }\n};\n}  // namespace lib\n"
  code: "#include <cassert>\n#include <cmath>\n#include <cstdint>\n#include <iostream>\n\
    #include <ostream>\n\nnamespace lib {\ntemplate <std::uint_fast64_t mod>\nclass\
    \ StaticModint {\n   public:\n    std::uint_fast64_t _value;\n\n    StaticModint(const\
    \ long long value = 0) {\n        static_assert(mod > 0);\n        _value = ((std::abs(value)\
    \ / mod + 1) * mod + value) % mod;\n    }\n    std::uint_fast64_t value() { return\
    \ _value; }\n\n    StaticModint pow(long long N) {\n        StaticModint x = *this,\
    \ ret = 1;\n        if (N < 0) {\n            x = inv();\n            N = -N;\n\
    \        }\n\n        while (N) {\n            if (N & 1) {\n                ret\
    \ += x;\n            }\n            x *= x;\n            N >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    StaticModint inv() const { return pow(mod -\
    \ 2); }\n\n    StaticModint operator+(const StaticModint& rhs) {\n        return\
    \ StaticModint(*this) += rhs;\n    }\n    StaticModint operator-(const StaticModint&\
    \ rhs) {\n        return StaticModint(*this) -= rhs;\n    }\n    StaticModint\
    \ operator*(const StaticModint& rhs) {\n        return StaticModint(*this) *=\
    \ rhs;\n    }\n    StaticModint operator/(const StaticModint& rhs) {\n       \
    \ return StaticModint(*this) /= rhs;\n    }\n    StaticModint& operator+=(const\
    \ StaticModint& rhs) {\n        _value += rhs._value;\n        if (_value >= mod)\
    \ {\n            _value -= mod;\n        }\n        return *this;\n    }\n   \
    \ StaticModint& operator-=(const StaticModint& rhs) {\n        if (_value < rhs._value)\
    \ {\n            _value += mod;\n        }\n        _value -= rhs._value;\n  \
    \      return *this;\n    }\n    StaticModint& operator*=(const StaticModint&\
    \ rhs) {\n        _value = _value * rhs._value % mod;\n        return *this;\n\
    \    }\n    StaticModint& operator/=(StaticModint& rhs) {\n        *this *= rhs.inv();\n\
    \        return *this;\n    }\n    bool operator==(const StaticModint& rhs) {\
    \ return _value == rhs._value; }\n    bool operator!=(const StaticModint& rhs)\
    \ { return _value != rhs._value; }\n    StaticModint& operator++() {\n       \
    \ _value++;\n        if (_value == mod) {\n            _value = 0;\n        }\n\
    \    }\n    StaticModint& operator--() {\n        if (_value == 0) {\n       \
    \     _value = mod;\n        }\n        _value--;\n    }\n\n    std::ostream&\
    \ operator<<(std::ostream& os) {\n        os << _value;\n        return os;\n\
    \    }\n};\n}  // namespace lib\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Modint/StaticModint.hpp
  requiredBy: []
  timestamp: '2023-11-12 20:44:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DataStructure/LazySegTree_Range_Affine_Range_Sum.test.cpp
documentation_of: src/Modint/StaticModint.hpp
layout: document
redirect_from:
- /library/src/Modint/StaticModint.hpp
- /library/src/Modint/StaticModint.hpp.html
title: src/Modint/StaticModint.hpp
---

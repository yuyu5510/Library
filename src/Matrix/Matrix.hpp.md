---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Matrix/Matrix.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace lib {\ntemplate <class T>\nclass Matrix {\n   public:\n\
    \    Matrix(int N, int M)\n        : Matrix(std::vector<std::vector<T>>(N, std::vector<T>(M)))\
    \ {}\n    Matrix(std::vector<std::vector<T>>& matrix)\n        : _matrix(matrix),\
    \ _N((int)matrix.size()) {\n        assert(_N);\n        _M = (int)(_matrix[0].size());\n\
    \        assert(_M);\n        for (int i = 1; i < _N; i++) {\n            assert(_M\
    \ == (int)(_matrix[i].size()));\n        }\n    }\n    Matrix(const Matrix& mat)\
    \ : _N(mat._N), _M(mat._M), _matrix(mat._matrix) {}\n    int N() { return _N;\
    \ }\n    int M() { return _M; }\n    std::vector<std::vector<T>> matrix() { return\
    \ _matrix; }\n    T get(int i, int j) {\n        assert(0 <= i && i < _N);\n \
    \       assert(0 <= j && j < _M);\n        return matrix[i][j];\n    }\n    void\
    \ set(int i, int j, T value) {\n        assert(0 <= i && i < _N);\n        assert(0\
    \ <= j && j < _M);\n        matrix[i][j] = value;\n        return;\n    }\n\n\
    \    Matrix pow(long long n, T identity = 1) {\n        // \u6B63\u65B9\u884C\u5217\
    \u3067\u306F\u306A\u3044\u6642\u8A08\u7B97\u4E0D\u53EF\n        assert(_N == _M);\n\
    \        assert(n >= 0);\n        Matrix ret(_N, _M);\n        for (int i = 0;\
    \ i < _N; i++) {\n            ret[i][i] = identity;\n        }\n\n        Matrix\
    \ mul = *this;\n        while (n) {\n            if (n & 1) {\n              \
    \  ret = ret * mul;\n            }\n            mul = mul * mul;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    Matrix operator+(const\
    \ Matrix rhs) { return Matrix(*this) += rhs; }\n    Matrix operator-(const Matrix\
    \ rhs) { return Matrix(*this) -= rhs; }\n    Matrix operator*(const Matrix rhs)\
    \ {\n        // (N, M) (M, K) \u2192 (N, K);\n        assert(_M == rhs._N);\n\
    \        Matrix ret(_N, rhs._M);\n        for (int i = 0; i < _N; i++) {\n   \
    \         for (int j = 0; j < rhs._M; j++) {\n                for (int k = 0;\
    \ k < _M; k++) {\n                    ret[i][j] += _matrix[i][k] * rhs._matrix[k][j];\n\
    \                }\n            }\n        }\n        return ret;\n    }\n\n \
    \   Matrix& operator=(const Matrix& rhs) {\n        _N = rhs._N;\n        _M =\
    \ rhs._M;\n        _matrix.resize(_N);\n        for (int i = 0; i < _N; i++) {\n\
    \            _matrix[i].resize(_M);\n        }\n        for (int i = 0; i < _N;\
    \ i++) {\n            for (int j = 0; j < _M; j++) {\n                _matrix[i][j]\
    \ = rhs._matrix[i][j];\n            }\n        }\n    }\n\n    Matrix& operator+=(const\
    \ Matrix& rhs) {\n        assert(_N == rhs._N && _M == rhs._M);\n        for (int\
    \ i = 0; i < _N; i++) {\n            for (int j = 0; j < _M; j++) {\n        \
    \        _matrix[i][j] += rhs._matrix[i][j];\n            }\n        }\n     \
    \   return *this;\n    }\n\n    Matrix& operator-=(const Matrix& rhs) {\n    \
    \    assert(_N == rhs._N && _M == rhs._m);\n        for (int i = 0; i < _N; i++)\
    \ {\n            for (int j = 0; j < _M; j++) {\n                _matrix[i][j]\
    \ -= rhs._matrix[i][j];\n            }\n        }\n        return *this;\n   \
    \ }\n\n   private:\n    int _N, _M;\n    std::vector<std::vector<T>> _matrix;\n\
    };\n}  // namespace lib\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace lib {\n\
    template <class T>\nclass Matrix {\n   public:\n    Matrix(int N, int M)\n   \
    \     : Matrix(std::vector<std::vector<T>>(N, std::vector<T>(M))) {}\n    Matrix(std::vector<std::vector<T>>&\
    \ matrix)\n        : _matrix(matrix), _N((int)matrix.size()) {\n        assert(_N);\n\
    \        _M = (int)(_matrix[0].size());\n        assert(_M);\n        for (int\
    \ i = 1; i < _N; i++) {\n            assert(_M == (int)(_matrix[i].size()));\n\
    \        }\n    }\n    Matrix(const Matrix& mat) : _N(mat._N), _M(mat._M), _matrix(mat._matrix)\
    \ {}\n    int N() { return _N; }\n    int M() { return _M; }\n    std::vector<std::vector<T>>\
    \ matrix() { return _matrix; }\n    T get(int i, int j) {\n        assert(0 <=\
    \ i && i < _N);\n        assert(0 <= j && j < _M);\n        return matrix[i][j];\n\
    \    }\n    void set(int i, int j, T value) {\n        assert(0 <= i && i < _N);\n\
    \        assert(0 <= j && j < _M);\n        matrix[i][j] = value;\n        return;\n\
    \    }\n\n    Matrix pow(long long n, T identity = 1) {\n        // \u6B63\u65B9\
    \u884C\u5217\u3067\u306F\u306A\u3044\u6642\u8A08\u7B97\u4E0D\u53EF\n        assert(_N\
    \ == _M);\n        assert(n >= 0);\n        Matrix ret(_N, _M);\n        for (int\
    \ i = 0; i < _N; i++) {\n            ret[i][i] = identity;\n        }\n\n    \
    \    Matrix mul = *this;\n        while (n) {\n            if (n & 1) {\n    \
    \            ret = ret * mul;\n            }\n            mul = mul * mul;\n \
    \           n >>= 1;\n        }\n        return ret;\n    }\n\n    Matrix operator+(const\
    \ Matrix rhs) { return Matrix(*this) += rhs; }\n    Matrix operator-(const Matrix\
    \ rhs) { return Matrix(*this) -= rhs; }\n    Matrix operator*(const Matrix rhs)\
    \ {\n        // (N, M) (M, K) \u2192 (N, K);\n        assert(_M == rhs._N);\n\
    \        Matrix ret(_N, rhs._M);\n        for (int i = 0; i < _N; i++) {\n   \
    \         for (int j = 0; j < rhs._M; j++) {\n                for (int k = 0;\
    \ k < _M; k++) {\n                    ret[i][j] += _matrix[i][k] * rhs._matrix[k][j];\n\
    \                }\n            }\n        }\n        return ret;\n    }\n\n \
    \   Matrix& operator=(const Matrix& rhs) {\n        _N = rhs._N;\n        _M =\
    \ rhs._M;\n        _matrix.resize(_N);\n        for (int i = 0; i < _N; i++) {\n\
    \            _matrix[i].resize(_M);\n        }\n        for (int i = 0; i < _N;\
    \ i++) {\n            for (int j = 0; j < _M; j++) {\n                _matrix[i][j]\
    \ = rhs._matrix[i][j];\n            }\n        }\n    }\n\n    Matrix& operator+=(const\
    \ Matrix& rhs) {\n        assert(_N == rhs._N && _M == rhs._M);\n        for (int\
    \ i = 0; i < _N; i++) {\n            for (int j = 0; j < _M; j++) {\n        \
    \        _matrix[i][j] += rhs._matrix[i][j];\n            }\n        }\n     \
    \   return *this;\n    }\n\n    Matrix& operator-=(const Matrix& rhs) {\n    \
    \    assert(_N == rhs._N && _M == rhs._m);\n        for (int i = 0; i < _N; i++)\
    \ {\n            for (int j = 0; j < _M; j++) {\n                _matrix[i][j]\
    \ -= rhs._matrix[i][j];\n            }\n        }\n        return *this;\n   \
    \ }\n\n   private:\n    int _N, _M;\n    std::vector<std::vector<T>> _matrix;\n\
    };\n}  // namespace lib"
  dependsOn: []
  isVerificationFile: false
  path: src/Matrix/Matrix.hpp
  requiredBy: []
  timestamp: '2023-11-12 22:03:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Matrix/Matrix.hpp
layout: document
redirect_from:
- /library/src/Matrix/Matrix.hpp
- /library/src/Matrix/Matrix.hpp.html
title: src/Matrix/Matrix.hpp
---

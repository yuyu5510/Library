#pragma once

#include <cassert>
#include <vector>

namespace lib {
template <class T>
class Matrix {
   public:
    Matrix(int N, int M)
        : Matrix(std::vector<std::vector<T>>(N, std::vector<T>(M))) {}
    Matrix(std::vector<std::vector<T>>& matrix)
        : _matrix(matrix), _N((int)matrix.size()) {
        assert(_N);
        _M = (int)(_matrix[0].size());
        assert(_M);
        for (int i = 1; i < _N; i++) {
            assert(_M == (int)(_matrix[i].size()));
        }
    }
    Matrix(const Matrix& mat) : _N(mat._N), _M(mat._M), _matrix(mat._matrix) {}
    int N() { return _N; }
    int M() { return _M; }
    std::vector<std::vector<T>> matrix() { return _matrix; }
    T get(int i, int j) {
        assert(0 <= i && i < _N);
        assert(0 <= j && j < _M);
        return matrix[i][j];
    }
    void set(int i, int j, T value) {
        assert(0 <= i && i < _N);
        assert(0 <= j && j < _M);
        matrix[i][j] = value;
        return;
    }

    Matrix pow(long long n, T identity = 1) {
        // 正方行列ではない時計算不可
        assert(_N == _M);
        assert(n >= 0);
        Matrix ret(_N, _M);
        for (int i = 0; i < _N; i++) {
            ret[i][i] = identity;
        }

        Matrix mul = *this;
        while (n) {
            if (n & 1) {
                ret = ret * mul;
            }
            mul = mul * mul;
            n >>= 1;
        }
        return ret;
    }

    Matrix operator+(const Matrix rhs) { return Matrix(*this) += rhs; }
    Matrix operator-(const Matrix rhs) { return Matrix(*this) -= rhs; }
    Matrix operator*(const Matrix rhs) {
        // (N, M) (M, K) → (N, K);
        assert(_M == rhs._N);
        Matrix ret(_N, rhs._M);
        for (int i = 0; i < _N; i++) {
            for (int j = 0; j < rhs._M; j++) {
                for (int k = 0; k < _M; k++) {
                    ret[i][j] += _matrix[i][k] * rhs._matrix[k][j];
                }
            }
        }
        return ret;
    }

    Matrix& operator=(const Matrix& rhs) {
        _N = rhs._N;
        _M = rhs._M;
        _matrix.resize(_N);
        for (int i = 0; i < _N; i++) {
            _matrix[i].resize(_M);
        }
        for (int i = 0; i < _N; i++) {
            for (int j = 0; j < _M; j++) {
                _matrix[i][j] = rhs._matrix[i][j];
            }
        }
    }

    Matrix& operator+=(const Matrix& rhs) {
        assert(_N == rhs._N && _M == rhs._M);
        for (int i = 0; i < _N; i++) {
            for (int j = 0; j < _M; j++) {
                _matrix[i][j] += rhs._matrix[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& rhs) {
        assert(_N == rhs._N && _M == rhs._m);
        for (int i = 0; i < _N; i++) {
            for (int j = 0; j < _M; j++) {
                _matrix[i][j] -= rhs._matrix[i][j];
            }
        }
        return *this;
    }

   private:
    int _N, _M;
    std::vector<std::vector<T>> _matrix;
};
}  // namespace lib
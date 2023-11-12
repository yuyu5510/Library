#pragma once

#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

namespace lib {
template <class T>
class BIT {
   public:
    BIT(int N) : _N(N), _bit(_N) {}
    void add(int idx, T value) {
        assert(0 <= idx && idx < _N);
        idx++;
        while (idx <= _N) {
            _bit[idx - 1] += value;
            idx += idx & -idx;
        }
    }

    T sum(int idx) {
        assert(0 <= idx && idx <= _N);
        T value = 0;
        while (idx > 0) {
            value += _bit[idx - 1];
            idx -= idx & -idx;
        }
        return value;
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _N);
        return sum(r) - sum(l);
    }

   private:
    int _N;
    std::vector<T> _bit;
};
}  // namespace lib
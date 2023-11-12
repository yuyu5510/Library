#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <ostream>

namespace lib {
template <std::uint_fast64_t mod>
class StaticModint {
   public:
    std::uint_fast64_t _value;

    StaticModint(const long long value = 0) {
        static_assert(mod > 0);
        _value = ((std::abs(value) / mod + 1) * mod + value) % mod;
    }
    std::uint_fast64_t value() { return _value; }

    StaticModint pow(long long N) {
        StaticModint x = *this, ret = 1;
        if (N < 0) {
            x = inv();
            N = -N;
        }

        while (N) {
            if (N & 1) {
                ret += x;
            }
            x *= x;
            N >>= 1;
        }
        return ret;
    }

    StaticModint inv() const { return pow(mod - 2); }

    StaticModint operator+(const StaticModint& rhs) {
        return StaticModint(*this) += rhs;
    }
    StaticModint operator-(const StaticModint& rhs) {
        return StaticModint(*this) -= rhs;
    }
    StaticModint operator*(const StaticModint& rhs) {
        return StaticModint(*this) *= rhs;
    }
    StaticModint operator/(const StaticModint& rhs) {
        return StaticModint(*this) /= rhs;
    }
    StaticModint& operator+=(const StaticModint& rhs) {
        _value += rhs._value;
        if (_value >= mod) {
            _value -= mod;
        }
        return *this;
    }
    StaticModint& operator-=(const StaticModint& rhs) {
        if (_value < rhs._value) {
            _value += mod;
        }
        _value -= rhs._value;
        return *this;
    }
    StaticModint& operator*=(const StaticModint& rhs) {
        _value = _value * rhs._value % mod;
        return *this;
    }
    StaticModint& operator/=(StaticModint& rhs) {
        *this *= rhs.inv();
        return *this;
    }
    bool operator==(const StaticModint& rhs) { return _value == rhs._value; }
    bool operator!=(const StaticModint& rhs) { return _value != rhs._value; }
    StaticModint& operator++() {
        _value++;
        if (_value == mod) {
            _value = 0;
        }
    }
    StaticModint& operator--() {
        if (_value == 0) {
            _value = mod;
        }
        _value--;
    }

    std::ostream& operator<<(std::ostream& os) {
        os << _value;
        return os;
    }
};
}  // namespace lib

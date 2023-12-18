#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

namespace lib {
class Prime {
   public:
    bool is_prime(__uint128_t n) {
        assert(n > 0);
        if (n == 1) {
            return false;
        }
        __uint128_t check[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        __uint128_t index = n - 1;
        // div 2^x (x is max of index % 2^x == 0)
        index = index / (index & -index);
        for (__uint128_t cp : check) {
            if (n == cp) {
                return true;
            }
            __uint128_t t_index = index;
            __uint128_t t_exp = power(cp, t_index, n);
            if (t_exp == 1) {
                continue;
            }
            // for all k | a^(index << k) != -1 → composite
            while (t_exp != n - 1) {
                t_exp = (t_exp * t_exp) % n;
                if (t_index == n - 1 || t_exp == 1) {
                    return false;
                }
                t_index <<= 1;
            }
        }
        return true;
    }

   private:
    __uint128_t power(__uint128_t x, __uint128_t n, __uint128_t mod) {
        __uint128_t ret = 1;
        while (n) {
            if (n & 1) {
                ret = (ret * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1;
        }
        return ret;
    }
};
}  // namespace lib
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

namespace lib {
class Prime {
   public:
    bool is_prime(std::uint_fast64_t number) {
        assert(number > 0);
        if (number == 1) {
            return false;
        }
        __uint128_t n = number;
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

    std::uint_fast64_t find_prime_factor(std::uint_fast64_t n) {
        std::uint_fast64_t log = 1;
        __uint128_t ms = 1;
        while (ms <= n) {
            ms <<= 1;
            log++;
        }
        log--;
        std::uint_fast64_t sqrt_eight_n =
            (static_cast<std::uint_fast64_t>(1) << (log / 8)) + 1;

        for (std::uint_fast64_t c = 1; c < 100; c++) {
            auto func = [&](std::uint_fast64_t x) {
                return static_cast<std::uint_fast64_t>(
                    (static_cast<__uint128_t>(x) * x + c) % n);
            };
            std::uint_fast64_t x = 0, yhold = -1;
            std::uint_fast64_t y = 2, gcdhold = 1, r = 1, k = 0;
            __uint128_t summ = 1;
            while (gcdhold == 1) {
                x = y;
                for (std::uint_fast64_t i = 0; i < r; i++) {
                    y = func(y);
                }
                k = 0;
                while (k < r && gcdhold == 1) {
                    yhold = y;
                    for (std::uint_fast64_t i = 0;
                         i < std::min(sqrt_eight_n, r - k); i++) {
                        y = func(y);
                        summ = (summ * abssub(x, y)) % n;
                    }
                    gcdhold = gcd(summ, n);
                    k += sqrt_eight_n;
                }
                r <<= 1;
            }

            if (gcdhold == n) {
                gcdhold = 1;
                while (gcdhold == 1) {
                    yhold = func(yhold);
                    gcdhold = gcd(abssub(x, yhold), n);
                }
            }

            if (gcdhold < n) {
                if (is_prime(gcdhold)) {
                    return gcdhold;
                } else if (is_prime(n / gcdhold)) {
                    return n / gcdhold;
                }
                return find_prime_factor(gcdhold);
            }
        }
        return -1;
    }

    std::vector<std::pair<std::uint_fast64_t, std::uint_fast64_t>> factorize(
        __uint128_t n) {
        std::vector<std::pair<std::uint_fast64_t, std::uint_fast64_t>> ret;
        std::uint_fast64_t cnt = 0;

        std::uint_fast64_t primes_under100[] = {
            2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        for (std::uint_fast64_t p : primes_under100) {
            cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            if (cnt) {
                ret.emplace_back(p, cnt);
            }
        }

        if (n == 1) {
            return ret;
        }
        if (is_prime(n)) {
            ret.emplace_back(n, 1);
            return ret;
        }

        std::uint_fast64_t fac;
        while (n > 1 && !is_prime(n)) {
            fac = find_prime_factor(n);
            cnt = 0;
            while (n % fac == 0) {
                n /= fac;
                cnt++;
            }
            ret.emplace_back(fac, cnt);
        }

        if (n > 1) {
            ret.emplace_back(n, 1);
        }
        std::sort(ret.begin(), ret.end());
        return ret;
    }

   private:
    std::uint_fast64_t abssub(std::uint_fast64_t a, std::uint_fast64_t b) {
        if (a >= b) {
            return a - b;
        }
        return b - a;
    }

    std::uint_fast64_t gcd(std::uint_fast64_t a, std::uint_fast64_t b) {
        while (b) {
            std::uint_fast64_t tmp = a;
            a = b;
            b = tmp % a;
        }
        return a;
    }
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
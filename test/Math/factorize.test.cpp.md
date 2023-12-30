---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/prime.hpp
    title: Prime
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/Math/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/Math/prime.hpp\"\n\
    #include <algorithm>\n#include <cassert>\n#include <cstdint>\n#line 6 \"src/Math/prime.hpp\"\
    \n\nnamespace lib {\nclass Prime {\n   public:\n    bool is_prime(std::uint_fast64_t\
    \ number) {\n        assert(number > 0);\n        if (number == 1) {\n       \
    \     return false;\n        }\n        __uint128_t n = number;\n        __uint128_t\
    \ check[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};\n        __uint128_t\
    \ index = n - 1;\n        // div 2^x (x is max of index % 2^x == 0)\n        index\
    \ = index / (index & -index);\n        for (__uint128_t cp : check) {\n      \
    \      if (n == cp) {\n                return true;\n            }\n         \
    \   __uint128_t t_index = index;\n            __uint128_t t_exp = power(cp, t_index,\
    \ n);\n            if (t_exp == 1) {\n                continue;\n            }\n\
    \            // for all k | a^(index << k) != -1 \u2192 composite\n          \
    \  while (t_exp != n - 1) {\n                t_exp = (t_exp * t_exp) % n;\n  \
    \              if (t_index == n - 1 || t_exp == 1) {\n                    return\
    \ false;\n                }\n                t_index <<= 1;\n            }\n \
    \       }\n        return true;\n    }\n\n    std::uint_fast64_t find_prime_factor(std::uint_fast64_t\
    \ n) {\n        std::uint_fast64_t log = 1;\n        __uint128_t ms = 1;\n   \
    \     while (ms <= n) {\n            ms <<= 1;\n            log++;\n        }\n\
    \        log--;\n        std::uint_fast64_t sqrt_eight_n =\n            (static_cast<std::uint_fast64_t>(1)\
    \ << (log / 8)) + 1;\n\n        for (std::uint_fast64_t c = 1; c < 100; c++) {\n\
    \            auto func = [&](std::uint_fast64_t x) {\n                return static_cast<std::uint_fast64_t>(\n\
    \                    (static_cast<__uint128_t>(x) * x + c) % n);\n           \
    \ };\n            std::uint_fast64_t x = 0, yhold = -1;\n            std::uint_fast64_t\
    \ y = 2, gcdhold = 1, r = 1, k = 0;\n            __uint128_t summ = 1;\n     \
    \       while (gcdhold == 1) {\n                x = y;\n                for (std::uint_fast64_t\
    \ i = 0; i < r; i++) {\n                    y = func(y);\n                }\n\
    \                k = 0;\n                while (k < r && gcdhold == 1) {\n   \
    \                 yhold = y;\n                    for (std::uint_fast64_t i =\
    \ 0;\n                         i < std::min(sqrt_eight_n, r - k); i++) {\n   \
    \                     y = func(y);\n                        summ = (summ * abssub(x,\
    \ y)) % n;\n                    }\n                    gcdhold = gcd(summ, n);\n\
    \                    k += sqrt_eight_n;\n                }\n                r\
    \ <<= 1;\n            }\n\n            if (gcdhold == n) {\n                gcdhold\
    \ = 1;\n                while (gcdhold == 1) {\n                    yhold = func(yhold);\n\
    \                    gcdhold = gcd(abssub(x, yhold), n);\n                }\n\
    \            }\n\n            if (gcdhold < n) {\n                if (is_prime(gcdhold))\
    \ {\n                    return gcdhold;\n                } else if (is_prime(n\
    \ / gcdhold)) {\n                    return n / gcdhold;\n                }\n\
    \                return find_prime_factor(gcdhold);\n            }\n        }\n\
    \        return -1;\n    }\n\n    std::vector<std::pair<std::uint_fast64_t, std::uint_fast64_t>>\
    \ factorize(\n        __uint128_t n) {\n        std::vector<std::pair<std::uint_fast64_t,\
    \ std::uint_fast64_t>> ret;\n        std::uint_fast64_t cnt = 0;\n\n        std::uint_fast64_t\
    \ primes_under100[] = {\n            2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31,\
    \ 37, 41,\n            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};\n    \
    \    for (std::uint_fast64_t p : primes_under100) {\n            cnt = 0;\n  \
    \          while (n % p == 0) {\n                n /= p;\n                cnt++;\n\
    \            }\n            if (cnt) {\n                ret.emplace_back(p, cnt);\n\
    \            }\n        }\n\n        if (n == 1) {\n            return ret;\n\
    \        }\n        if (is_prime(n)) {\n            ret.emplace_back(n, 1);\n\
    \            return ret;\n        }\n\n        std::uint_fast64_t fac;\n     \
    \   while (n > 1 && !is_prime(n)) {\n            fac = find_prime_factor(n);\n\
    \            cnt = 0;\n            while (n % fac == 0) {\n                n /=\
    \ fac;\n                cnt++;\n            }\n            ret.emplace_back(fac,\
    \ cnt);\n        }\n\n        if (n > 1) {\n            ret.emplace_back(n, 1);\n\
    \        }\n        std::sort(ret.begin(), ret.end());\n        return ret;\n\
    \    }\n\n   private:\n    std::uint_fast64_t abssub(std::uint_fast64_t a, std::uint_fast64_t\
    \ b) {\n        if (a >= b) {\n            return a - b;\n        }\n        return\
    \ b - a;\n    }\n\n    std::uint_fast64_t gcd(std::uint_fast64_t a, std::uint_fast64_t\
    \ b) {\n        while (b) {\n            std::uint_fast64_t tmp = a;\n       \
    \     a = b;\n            b = tmp % a;\n        }\n        return a;\n    }\n\
    \    __uint128_t power(__uint128_t x, __uint128_t n, __uint128_t mod) {\n    \
    \    __uint128_t ret = 1;\n        while (n) {\n            if (n & 1) {\n   \
    \             ret = (ret * x) % mod;\n            }\n            x = (x * x) %\
    \ mod;\n            n >>= 1;\n        }\n        return ret;\n    }\n};\n}  //\
    \ namespace lib\n#line 7 \"test/Math/factorize.test.cpp\"\n\nint main() {\n  \
    \  lib::Prime prime;\n    int Q;\n    std::cin >> Q;\n    for (int i = 0; i <\
    \ Q; i++) {\n        unsigned long long n;\n        std::cin >> n;\n        auto\
    \ factor = prime.factorize(n);\n        unsigned long long siz = 0;\n        for\
    \ (auto [n, x] : factor) {\n            siz += x;\n        }\n        std::cout\
    \ << siz;\n        for (auto [n, x] : factor) {\n            for (int j = 0; j\
    \ < (int)x; j++) {\n                std::cout << ' ' << n;\n            }\n  \
    \      }\n        std::cout << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../src/Math/prime.hpp\"\n\nint\
    \ main() {\n    lib::Prime prime;\n    int Q;\n    std::cin >> Q;\n    for (int\
    \ i = 0; i < Q; i++) {\n        unsigned long long n;\n        std::cin >> n;\n\
    \        auto factor = prime.factorize(n);\n        unsigned long long siz = 0;\n\
    \        for (auto [n, x] : factor) {\n            siz += x;\n        }\n    \
    \    std::cout << siz;\n        for (auto [n, x] : factor) {\n            for\
    \ (int j = 0; j < (int)x; j++) {\n                std::cout << ' ' << n;\n   \
    \         }\n        }\n        std::cout << std::endl;\n    }\n}"
  dependsOn:
  - src/Math/prime.hpp
  isVerificationFile: true
  path: test/Math/factorize.test.cpp
  requiredBy: []
  timestamp: '2023-12-31 01:11:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Math/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/Math/factorize.test.cpp
- /verify/test/Math/factorize.test.cpp.html
title: test/Math/factorize.test.cpp
---

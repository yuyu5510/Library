#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include <iostream>
#include <vector>

#include "../../src/Math/prime.hpp"

int main() {
    lib::Prime prime;
    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        unsigned long long n;
        std::cin >> n;
        bool is_p = prime.is_prime(n);
        if (is_p) {
            std::cout << "Yes" << '\n';
        } else {
            std::cout << "No" << '\n';
        }
    }
}
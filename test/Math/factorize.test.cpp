#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

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
        auto factor = prime.factorize(n);
        unsigned long long siz = 0;
        for (auto [n, x] : factor) {
            siz += x;
        }
        std::cout << siz;
        for (auto [n, x] : factor) {
            for (int j = 0; j < (int)x; j++) {
                std::cout << ' ' << n;
            }
        }
        std::cout << std::endl;
    }
}
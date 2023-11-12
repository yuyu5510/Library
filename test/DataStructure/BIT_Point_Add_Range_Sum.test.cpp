#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <vector>

#include "../../src/DataStructure/BIT.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<long long> A(N);
    lib::BIT<long long> bit(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        bit.add(i, A[i]);
    }

    for (int i = 0; i < Q; i++) {
        long long t, l, r;
        std::cin >> t >> l >> r;
        if (t == 0) {
            bit.add(l, r);
        }
        if (t == 1) {
            std::cout << bit.sum(l, r) << '\n';
        }
    }
}
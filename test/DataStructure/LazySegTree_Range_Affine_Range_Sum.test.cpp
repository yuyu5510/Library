#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>

#include "../../src/DataStructure/LazySegTree.hpp"
#include "../../src/Modint/StaticModint.hpp"

using mint = lib::StaticModint<998244353>;

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::pair<mint, mint>> A(N);
    for (int i = 0; i < N; i++) {
        long long input;
        std::cin >> input;
        A[i] = std::make_pair(input, 1);
    }
    lib::LazySegTree<std::pair<mint, mint>, std::pair<mint, mint>> seg(
        A,
        [](std::pair<mint, mint> a,
           std::pair<mint, mint> b) -> std::pair<mint, mint> {
            return std::make_pair(a.first + b.first, a.second + b.second);
        },
        std::make_pair(0, 0),
        [](std::pair<mint, mint> f,
           std::pair<mint, mint> a) -> std::pair<mint, mint> {
            return std::make_pair(f.first * a.first + f.second * a.second,
                                  a.second);
        },
        [](std::pair<mint, mint> a,
           std::pair<mint, mint> b) -> std::pair<mint, mint> {
            return std::make_pair(a.first * b.first,
                                  a.first * b.second + a.second);
        },
        std::make_pair(1, 0));

    for (int i = 0; i < Q; i++) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r;
            long long c, d;
            std::cin >> l >> r >> c >> d;
            seg.apply(l, r, std::make_pair(c, d));
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.prod(l, r).first.value() << '\n';
        }
    }
}
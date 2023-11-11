#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "../../src/DataStructure/UnionFind.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    lib::UnionFind uf(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            std::cout << uf.same(u, v) << '\n';
        }
    }
}
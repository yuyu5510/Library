#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <vector>
#include "../../src/DataStructure/SegTree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<long long> A(N);
    for(int i = 0;i < N;i++){
        std::cin >> A[i];
    }

    lib::SegTree<long long> seg(A, 
        [](long long a, long long b) -> long long{return a + b;}, 
        0LL);

    for(int i = 0;i < Q;i++){
        long long t, l, r;
        std::cin >> t >> l >> r;
        if(t == 0){
            seg.set(l, seg.get(l) + r);
        }
        if(t == 1){
            std::cout << seg.prod(l, r) << '\n';
        }
    }
}
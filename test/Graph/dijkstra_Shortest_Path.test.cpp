#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <iostream>
#include <vector>

#include "../../src/Graph/dijkstra.hpp"

int main() {
    int N, M, s, t;
    std::cin >> N >> M >> s >> t;
    lib::Graph<long long> G(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        G.add_edge(a, b, c);
    }

    auto dist = lib::dijkstra(s, G);
    std::vector<int> path;
    long long X = dist[t].first;
    if (X == std::numeric_limits<long long>::max()) {
        std::cout << -1 << '\n';
        return 0;
    }

    while (dist[t].second != -1) {
        path.push_back(t);
        t = dist[t].second;
    }
    path.push_back(s);
    int Y = (int)path.size() - 1;
    std::cout << X << ' ' << Y << '\n';
    for (int i = Y; i > 0; i--) {
        std::cout << path[i] << ' ' << path[i - 1] << '\n';
    }
}
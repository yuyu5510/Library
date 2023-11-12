#pragma once

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

namespace lib {
template <class T>
struct Edge {
   public:
    Edge() : _to(-1), _cost(0) {}
    Edge(int to, T cost = 1) : _to(to), _cost(cost) {}
    int to() { return _to; }
    T cost() { return _cost; }
    void change_cost(const T& val) { _cost = val; }
    void change_to(const int& val) { _to = val; }

   private:
    int _to;
    T _cost;
};

template <class T = long long>
class Graph {
   public:
    Graph(int N) : N(N), G(N) {}
    void add_edge(int u, int v, T cost = 1) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        G[u].push_back(Edge<T>(v, cost));
        return;
    }

    void erase_edge(int u, int idx) {
        assert(0 <= u && u < N);
        assert(0 <= idx && idx < (int)G[u].size());
        swap_edge(G[u][idx], G[u].back());
        G[u].pop_back();
        return;
    }

    void erase_edge_vertex(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        int last = (int)(G[u].size() - 1);
        for (int i = 0; i < (int)(G[u].size()); i++) {
            if (i > last) {
                break;
            }
            if (G[u][i].to() == v) {
                swap_edge(G[u][i], G[u][last]);
                last--;
            }
        }

        for (int i = last; i < (int)(G[u].size()); i++) {
            G[u][i].pop_back();
        }
        return;
    }

    const std::vector<Edge<T>>& operator[](int i) const {
        assert(0 <= i && i < N);
        return G[i];
    }

    std::size_t size() const { return G.size(); }

   private:
    const int N;
    std::vector<std::vector<Edge<T>>> G;
    void swap_edge(Edge<T>& e1, Edge<T>& e2) {
        int to1 = e1.to();
        e1.change_to(e2.to());
        e2.change_to(to1);

        T cost1 = e1.cost;
        e1.change_cost(e2.cost());
        e2.change_ost(cost1);
        return;
    }
};
}  // namespace lib
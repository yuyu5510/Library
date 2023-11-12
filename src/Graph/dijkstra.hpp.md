---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/Graph/Graph.hpp
    title: Graph
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/Graph/dijkstra_Shortest_Path.cpp
    title: test/Graph/dijkstra_Shortest_Path.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/dijkstra.hpp\"\n\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\n#line 2 \"src/Graph/Graph.hpp\"\
    \n\n#line 4 \"src/Graph/Graph.hpp\"\n#include <iostream>\n#line 7 \"src/Graph/Graph.hpp\"\
    \n\nnamespace lib {\ntemplate <class T>\nstruct Edge {\n   public:\n    Edge()\
    \ : _to(-1), _cost(0) {}\n    Edge(int to, T cost = 1) : _to(to), _cost(cost)\
    \ {}\n    int to() { return _to; }\n    T cost() { return _cost; }\n    void change_cost(const\
    \ T& val) { *this._cost = val; }\n    void change_to(const int& val) { *this._to\
    \ = val; }\n\n   private:\n    int _to;\n    T _cost;\n};\n\ntemplate <class T\
    \ = long long>\nclass Graph {\n   public:\n    Graph(int N) : N(N), G(N) {}\n\
    \    void add_edge(int u, int v, T cost = 1) {\n        assert(0 <= u && u < N);\n\
    \        assert(0 <= v && v < N);\n        G[u].push_back(Edge<T>(v, cost));\n\
    \        return;\n    }\n\n    void erase_edge(int u, int idx) {\n        assert(0\
    \ <= u && u < N);\n        assert(0 <= idx && idx < (int)G[u].size());\n     \
    \   swap_edge(G[u][idx], G[u].back());\n        G[u].pop_back();\n        return;\n\
    \    }\n\n    void erase_edge_vertex(int u, int v) {\n        assert(0 <= u &&\
    \ u < N);\n        assert(0 <= v && v < N);\n        int last = (int)(G[u].size()\
    \ - 1);\n        for (int i = 0; i < (int)(G[u].size()); i++) {\n            if\
    \ (i > last) {\n                break;\n            }\n            if (G[u][i].to()\
    \ == v) {\n                swap_edge(G[u][i], G[u][last]);\n                last--;\n\
    \            }\n        }\n\n        for (int i = last; i < (int)(G[u].size());\
    \ i++) {\n            G[u][i].pop_back();\n        }\n        return;\n    }\n\
    \n    const std::vector<Edge<T>>& operator[](int i) const {\n        assert(0\
    \ <= i && i < N);\n        return G[i];\n    }\n\n    std::size_t size() const\
    \ { return G.size(); }\n\n   private:\n    const int N;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n    void swap_edge(Edge<T>& e1, Edge<T>& e2) {\n        int to1 = e1.to();\n\
    \        e1.change_to(e2.to());\n        e2.change_to(to1);\n\n        T cost1\
    \ = e1.cost;\n        e1.change_cost(e2.cost());\n        e2.change_ost(cost1);\n\
    \        return;\n    }\n};\n}  // namespace lib\n#line 9 \"src/Graph/dijkstra.hpp\"\
    \n\nnamespace lib {\ntemplate <class T = long long>\nstd::vector<std::pair<T,\
    \ int>> dijkstra(int start, const Graph<T>& G,\n                             \
    \           T start_val = 0) {\n    assert(0 <= start && start < (int)G.size());\n\
    \    // \u8DDD\u96E2 \u3068 \u3069\u3053\u304B\u3089\u304B\u3092\u4FDD\u6301\n\
    \    std::vector<std::pair<T, int>> dist(\n        (int)G.size(), std::make_pair(std::numeric_limits<T>::max(),\
    \ -1));\n    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\n\
    \                        std::greater<std::pair<T, int>>>\n        que;\n    que.push(std::make_pair(start_val,\
    \ start));\n    dist[start].first = start_val;\n    while (!que.empty()) {\n \
    \       T dist_q = que.top().first, vertex = que.top().second;\n        que.pop();\n\
    \        if (dist[vertex].first < dist_q) {\n            continue;\n        }\n\
    \        for (Edge<T> edge : G[vertex]) {\n            // dist[vertex] is not\
    \ max()\n            if (dist[edge.to()].first > dist[vertex].first + edge.cost())\
    \ {\n                dist[edge.to()].first = dist[vertex].first + edge.cost();\n\
    \                dist[edge.to()].second = vertex;\n                que.push(std::make_pair(dist[edge.to()].first,\
    \ edge.to()));\n            }\n        }\n    }\n\n    return dist;\n}\n}  //\
    \ namespace lib\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\n#include \"Graph.hpp\"\n\nnamespace lib {\ntemplate <class\
    \ T = long long>\nstd::vector<std::pair<T, int>> dijkstra(int start, const Graph<T>&\
    \ G,\n                                        T start_val = 0) {\n    assert(0\
    \ <= start && start < (int)G.size());\n    // \u8DDD\u96E2 \u3068 \u3069\u3053\
    \u304B\u3089\u304B\u3092\u4FDD\u6301\n    std::vector<std::pair<T, int>> dist(\n\
    \        (int)G.size(), std::make_pair(std::numeric_limits<T>::max(), -1));\n\
    \    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\n\
    \                        std::greater<std::pair<T, int>>>\n        que;\n    que.push(std::make_pair(start_val,\
    \ start));\n    dist[start].first = start_val;\n    while (!que.empty()) {\n \
    \       T dist_q = que.top().first, vertex = que.top().second;\n        que.pop();\n\
    \        if (dist[vertex].first < dist_q) {\n            continue;\n        }\n\
    \        for (Edge<T> edge : G[vertex]) {\n            // dist[vertex] is not\
    \ max()\n            if (dist[edge.to()].first > dist[vertex].first + edge.cost())\
    \ {\n                dist[edge.to()].first = dist[vertex].first + edge.cost();\n\
    \                dist[edge.to()].second = vertex;\n                que.push(std::make_pair(dist[edge.to()].first,\
    \ edge.to()));\n            }\n        }\n    }\n\n    return dist;\n}\n}  //\
    \ namespace lib"
  dependsOn:
  - src/Graph/Graph.hpp
  isVerificationFile: false
  path: src/Graph/dijkstra.hpp
  requiredBy:
  - test/Graph/dijkstra_Shortest_Path.cpp
  timestamp: '2023-11-12 23:58:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/dijkstra.hpp
layout: document
title: dijkstra
---

# dijkstra
グラフの辺に負の重みが存在しない際に使える、ある頂点からの他の頂点への最短距離を計算します。

頂点数 $V$, 辺の数 $E$ とすると、
$O(ElogV)$ で計算できます。

## dijkstra
`dijkstra<T = long long>(int start, Graph<T> &G, T start_val = 0)`
- $Graph$ の型 $T$ (指定しないと long long)
- 始点 $s$
- 始点の距離 start_val (指定しないと0)
が必要です。

返り値は`std::vector<std::pair<T, int>>  dist`です。
dist\[v\].first は $s$ から $v$　までの最短距離、 dist\[v\].second は $s$ から $v$　までのある最短距離のパスで $v$ の一つ前の頂点が入ります。

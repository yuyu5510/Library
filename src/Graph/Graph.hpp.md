---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/Graph/dijkstra.hpp
    title: dijkstra
  - icon: ':warning:'
    path: test/Graph/dijkstra_Shortest_Path.cpp
    title: test/Graph/dijkstra_Shortest_Path.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/Graph.hpp\"\n\n#include <cassert>\n#include <iostream>\n\
    #include <queue>\n#include <vector>\n\nnamespace lib {\ntemplate <class T>\nstruct\
    \ Edge {\n   public:\n    Edge() : _to(-1), _cost(0) {}\n    Edge(int to, T cost\
    \ = 1) : _to(to), _cost(cost) {}\n    int to() { return _to; }\n    T cost() {\
    \ return _cost; }\n    void change_cost(const T& val) { *this._cost = val; }\n\
    \    void change_to(const int& val) { *this._to = val; }\n\n   private:\n    int\
    \ _to;\n    T _cost;\n};\n\ntemplate <class T = long long>\nclass Graph {\n  \
    \ public:\n    Graph(int N) : N(N), G(N) {}\n    void add_edge(int u, int v, T\
    \ cost = 1) {\n        assert(0 <= u && u < N);\n        assert(0 <= v && v <\
    \ N);\n        G[u].push_back(Edge<T>(v, cost));\n        return;\n    }\n\n \
    \   void erase_edge(int u, int idx) {\n        assert(0 <= u && u < N);\n    \
    \    assert(0 <= idx && idx < (int)G[u].size());\n        swap_edge(G[u][idx],\
    \ G[u].back());\n        G[u].pop_back();\n        return;\n    }\n\n    void\
    \ erase_edge_vertex(int u, int v) {\n        assert(0 <= u && u < N);\n      \
    \  assert(0 <= v && v < N);\n        int last = (int)(G[u].size() - 1);\n    \
    \    for (int i = 0; i < (int)(G[u].size()); i++) {\n            if (i > last)\
    \ {\n                break;\n            }\n            if (G[u][i].to() == v)\
    \ {\n                swap_edge(G[u][i], G[u][last]);\n                last--;\n\
    \            }\n        }\n\n        for (int i = last; i < (int)(G[u].size());\
    \ i++) {\n            G[u][i].pop_back();\n        }\n        return;\n    }\n\
    \n    const std::vector<Edge<T>>& operator[](int i) const {\n        assert(0\
    \ <= i && i < N);\n        return G[i];\n    }\n\n    std::size_t size() const\
    \ { return G.size(); }\n\n   private:\n    const int N;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n    void swap_edge(Edge<T>& e1, Edge<T>& e2) {\n        int to1 = e1.to();\n\
    \        e1.change_to(e2.to());\n        e2.change_to(to1);\n\n        T cost1\
    \ = e1.cost;\n        e1.change_cost(e2.cost());\n        e2.change_ost(cost1);\n\
    \        return;\n    }\n};\n}  // namespace lib\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iostream>\n#include <queue>\n\
    #include <vector>\n\nnamespace lib {\ntemplate <class T>\nstruct Edge {\n   public:\n\
    \    Edge() : _to(-1), _cost(0) {}\n    Edge(int to, T cost = 1) : _to(to), _cost(cost)\
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
    \        return;\n    }\n};\n}  // namespace lib"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/Graph.hpp
  requiredBy:
  - test/Graph/dijkstra_Shortest_Path.cpp
  - src/Graph/dijkstra.hpp
  timestamp: '2023-11-12 23:58:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/Graph.hpp
layout: document
title: Graph
---

# Graph
隣接グラフ方式で保持したグラフの基礎的操作を行うためのクラスです。

## コンストラクタ
`Graph<T> (int N)`

頂点数 $N$ のグラフを生成します。生成した段階で辺はありません。
T は辺の重みの型です。何も指定しなければ long long 型になります。
### 計算量
$O(N)$

## add_edge(int u, int v, T cost = 1)
頂点 $u$ と　頂点 $v$ を結ぶ、重み $cost$ の辺をグラフに追加します
### 計算量
$O(1)$

## erase_edge(int u, int idx)
$G[u]$ の $idx$ 番目の辺を除去します。
### 計算量
$O(1)$

## erase_edge(int u, int v)
$u$ と $v$ のつながっている辺を除去します。無向辺の場合は `erage_edge(v, u)` も呼び出す必要があることに注意してください。

### 計算量
$u$ の次数を $d(u)$ とすると、$O(d(u))$ です。

## size()
std::size_t 型で頂点数を返します。
### 計算量
$O(1)$


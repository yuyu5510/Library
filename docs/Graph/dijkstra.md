---
title: dijkstra
documentation_of: ./src/Graph/dijkstra.hpp
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

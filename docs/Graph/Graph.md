---
title: Graph
documentation_of: ./src/Graph/Graph.hpp
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


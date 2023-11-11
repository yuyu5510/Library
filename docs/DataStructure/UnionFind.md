# UnionFind
連結性の判定に使うデータ構造です。

## コンストラクタ
`UnionFind (int n)`

### 計算量
$O(N)$

## root(u)
頂点 $u$ が属するグループの根の番号を返します。

### 計算量
$O(\alpha(N))$

## unite(u, v)
頂点 $u$ と $v$ を連結し、trueを返します。\
すでに連結である場合はfalseを返します。

## 計算量
計算量は $O(\alpha(N))$ 

## same(u, v)
頂点 $u$ と $v$ が連結である時trueを返し、そうでない時、falseを返します。\
計算量は $O(\alpha(N))$ です。

## size(u)
頂点 $u$ と連結な頂点の数を返します。\
計算量は $O(\alpha(N))$ です。
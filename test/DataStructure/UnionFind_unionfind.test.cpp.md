---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind.hpp
    title: src/DataStructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/DataStructure/UnionFind_unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <iostream>\n\
    #line 2 \"src/DataStructure/UnionFind.hpp\"\n\n#line 4 \"src/DataStructure/UnionFind.hpp\"\
    \n#include <vector>\n\nnamespace lib{\n    class UnionFind {\n    public:\n  \
    \      std::vector<int> par, siz;\n        UnionFind(int n) : par(n, -1), siz(n,\
    \ 1) {}\n\n        // \u7D4C\u8DEF\u5727\u7E2E\u3042\u308A\n        int root(int\
    \ x) {\n            if (par[x] == -1) return x;\n            return par[x] = root(par[x]);\n\
    \        }\n\n        // \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\n        /*int root(int\
    \ x){\n            if(par[x] == -1) return x;\n            return root(par[x]);\n\
    \        } */\n\n        bool unite(int x, int y) {\n            int rx = root(x),\
    \ ry = root(y);\n            if (rx == ry) return false;\n            if (size(rx)\
    \ < size(ry)) std::swap(rx, ry);\n\n            par[ry] = rx;\n            siz[rx]\
    \ += siz[ry];\n            return true;\n        }\n\n        bool same(int x,\
    \ int y) { return root(x) == root(y); }\n\n        int size(int x) { return siz[root(x)];\
    \ }\n    };\n}\n#line 5 \"test/DataStructure/UnionFind_unionfind.test.cpp\"\n\n\
    int main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    lib::UnionFind uf(N);\n\
    \    for (int i = 0; i < Q; i++) {\n        int t, u, v;\n        std::cin >>\
    \ t >> u >> v;\n        if (t == 0) {\n            uf.unite(u, v);\n        }\
    \ else {\n            std::cout << uf.same(u, v) << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include \"../../src/DataStructure/UnionFind.hpp\"\n\nint main()\
    \ {\n    int N, Q;\n    std::cin >> N >> Q;\n    lib::UnionFind uf(N);\n    for\
    \ (int i = 0; i < Q; i++) {\n        int t, u, v;\n        std::cin >> t >> u\
    \ >> v;\n        if (t == 0) {\n            uf.unite(u, v);\n        } else {\n\
    \            std::cout << uf.same(u, v) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/DataStructure/UnionFind_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 00:32:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DataStructure/UnionFind_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/DataStructure/UnionFind_unionfind.test.cpp
- /verify/test/DataStructure/UnionFind_unionfind.test.cpp.html
title: test/DataStructure/UnionFind_unionfind.test.cpp
---

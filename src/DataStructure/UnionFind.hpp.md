---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DataStructure/UnionFind_unionfind.test.cpp
    title: test/DataStructure/UnionFind_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/UnionFind.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nnamespace lib{\n    class UnionFind {\n    public:\n    \
    \    std::vector<int> par, siz;\n        UnionFind(int n) : par(n, -1), siz(n,\
    \ 1) {}\n\n        // \u7D4C\u8DEF\u5727\u7E2E\u3042\u308A\n        int root(int\
    \ x) {\n            if (par[x] == -1) return x;\n            return par[x] = root(par[x]);\n\
    \        }\n\n        // \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\n        /*int root(int\
    \ x){\n            if(par[x] == -1) return x;\n            return root(par[x]);\n\
    \        } */\n\n        bool unite(int x, int y) {\n            int rx = root(x),\
    \ ry = root(y);\n            if (rx == ry) return false;\n            if (size(rx)\
    \ < size(ry)) std::swap(rx, ry);\n\n            par[ry] = rx;\n            siz[rx]\
    \ += siz[ry];\n            return true;\n        }\n\n        bool same(int x,\
    \ int y) { return root(x) == root(y); }\n\n        int size(int x) { return siz[root(x)];\
    \ }\n    };\n}\n"
  code: "#pragma once\n\n#include <iostream>\n#include <vector>\n\nnamespace lib{\n\
    \    class UnionFind {\n    public:\n        std::vector<int> par, siz;\n    \
    \    UnionFind(int n) : par(n, -1), siz(n, 1) {}\n\n        // \u7D4C\u8DEF\u5727\
    \u7E2E\u3042\u308A\n        int root(int x) {\n            if (par[x] == -1) return\
    \ x;\n            return par[x] = root(par[x]);\n        }\n\n        // \u7D4C\
    \u8DEF\u5727\u7E2E\u306A\u3057\n        /*int root(int x){\n            if(par[x]\
    \ == -1) return x;\n            return root(par[x]);\n        } */\n\n       \
    \ bool unite(int x, int y) {\n            int rx = root(x), ry = root(y);\n  \
    \          if (rx == ry) return false;\n            if (size(rx) < size(ry)) std::swap(rx,\
    \ ry);\n\n            par[ry] = rx;\n            siz[rx] += siz[ry];\n       \
    \     return true;\n        }\n\n        bool same(int x, int y) { return root(x)\
    \ == root(y); }\n\n        int size(int x) { return siz[root(x)]; }\n    };\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2023-11-12 00:32:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DataStructure/UnionFind_unionfind.test.cpp
documentation_of: src/DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFind.hpp
- /library/src/DataStructure/UnionFind.hpp.html
title: src/DataStructure/UnionFind.hpp
---

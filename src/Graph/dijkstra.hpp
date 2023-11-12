#pragma once

#include <cassert>
#include <limits>
#include <queue>
#include <vector>

#include "Graph.hpp"

namespace lib {
template <class T = long long>
std::vector<std::pair<T, int>> dijkstra(int start, const Graph<T>& G,
                                        T start_val = 0) {
    assert(0 <= start && start < (int)G.size());
    // 距離 と どこからかを保持
    std::vector<std::pair<T, int>> dist(
        (int)G.size(), std::make_pair(std::numeric_limits<T>::max(), -1));
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                        std::greater<std::pair<T, int>>>
        que;
    que.push(std::make_pair(start_val, start));
    dist[start].first = start_val;
    while (!que.empty()) {
        T dist_q = que.top().first, vertex = que.top().second;
        que.pop();
        if (dist[vertex].first < dist_q) {
            continue;
        }
        for (Edge<T> edge : G[vertex]) {
            // dist[vertex] is not max()
            if (dist[edge.to()].first > dist[vertex].first + edge.cost()) {
                dist[edge.to()].first = dist[vertex].first + edge.cost();
                dist[edge.to()].second = vertex;
                que.push(std::make_pair(dist[edge.to()].first, edge.to()));
            }
        }
    }

    return dist;
}
}  // namespace lib
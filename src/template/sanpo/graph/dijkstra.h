#include "../sol.cpp"

template <typename T>
struct edge {
  int v;
  T w;
  edge(int v, T w) : v(v), w(w) {}
};

template <typename T>
using graph = vector<vector<edge<T>>>;

template <typename T>
ll dijkstra(const graph<T>& ns, int src, int dst) {
  // distance from src
  vl dist(sz(g), LONG_LONG_MAX);
  dist[src] = 0;

  // {negative dist, corresponding vertex}
  // top element has the min dist
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    // outdated dist
    if (d > dist[u]) continue;

    // relaxation
    for (edge e : ns[u]) {
      if (dist[e.v] > dist[u] + e.w) {
        dist[e.v] = dist[u] + e.w;
        pq.push({dist[e.v], e.v});
      }
    }
  }
  return dist[dst];
}

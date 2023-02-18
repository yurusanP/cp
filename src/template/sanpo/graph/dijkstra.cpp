#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Edge {
  int to;
  int weight;
  Edge(int to, int weight) : to(to), weight(weight) {}
};

typedef vector<vector<Edge>> Graph;

int dijkstra(const Graph& graph, int src, int dst) {
  vi dist(sz(graph), 1e9);
  dist[src] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, src});
  while (!pq.empty()) {
    int d = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (d > dist[v]) continue;

    // relaxation
    for (Edge e : graph[v]) {
      if (dist[e.to] > dist[v] + e.weight) {
        dist[e.to] = dist[v] + e.weight;
        pq.push({dist[e.to], e.to});
      }
    }
  }
  return dist[dst];
}

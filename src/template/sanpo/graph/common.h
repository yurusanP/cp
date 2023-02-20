#ifndef SANPO_GRAPH_COMMON_H_
#define SANPO_GRAPH_COMMON_H_
#include "../sol.h"

template <typename T>
struct edge {
  int v;
  T w;
  edge(int v, T w) : v(v), w(w) {}
};

template <typename T>
using graph = vector<vector<edge<T>>>;

#endif

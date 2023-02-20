#ifndef SANPO_DATA_UFIND_H_
#define SANPO_DATA_UFIND_H_
#include "../sol.h"

struct ufind {
  // distinguished elements store the negative size
  // others store the distinguished index
  vi es;
  ufind(int n) : es(n, -1) {}
  int size(int x) { return -es[find(x)]; }
  int find(int x) { return es[x] < 0 ? x : find(es[x]); }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (es[x] > es[y]) {
      swap(x, y);
    }
    es[x] += es[y];
    es[y] = x;
  }
};

#endif

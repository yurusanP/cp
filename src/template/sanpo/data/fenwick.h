#ifndef SANPO_DATA_FENWICK_H_
#define SANPO_DATA_FENWICK_H_
#include "../sol.h"

template <typename T>
struct fenwick {
  // 0-indexed
  vector<T> fs;

  fenwick(int n) : fs(n) {}

  // es[ix] += x
  void update(int ix, T x) {
    for (; ix < sz(fs); ix |= ix + 1) {
      fs[ix] += x;
    }
  }

  // sum [0, ix)
  T query(int ix) {
    T res = 0;
    for (; ix > 0; ix &= ix - 1) {
      res += fs[ix - 1];
    }
    return res;
  }
};

#endif

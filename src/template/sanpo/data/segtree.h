#ifndef SANPO_DATA_SEGTREE_H_
#define SANPO_DATA_SEGTREE_H_
#include "../sol.h"

template <typename T, typename F = function<T(const T&, const T&)>>
struct zkw {
  int n;
  vector<T> es;
  F fn;
  T unit;

  zkw(const F& fn, T unit, int n) : fn(fn), n(n), es(n * 2, unit) {}

  void update(int ix, T x) {
    ix += n;
    es[ix] = x;
    for (; ix /= 2;) {
      es[ix] = fn(es[ix * 2], es[ix * 2 + 1]);
    }
  }

  // query [l, r)
  T query(int l, int r) {
    T res_l = unit, res_r = unit;
    l += n;
    r += n;
    for (; l < r; l /= 2, r /= 2) {
      if (l % 2) res_l = fn(res_l, es[l++]);
      if (r % 2) res_r = fn(es[--r], res_r);
    }
    return fn(res_l, res_r);
  }
};

#endif

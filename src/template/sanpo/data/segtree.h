#ifndef SANPO_DATA_SEGTREE_H_
#define SANPO_DATA_SEGTREE_H_
#include "../sol.h"

template <typename T, typename F = function<T(const T&, const T&)>>
struct zkw {
  F fn;
  T unit;
  int n;
  vector<T> fs;

  zkw(const F& fn, T unit, int n) : fn(fn), unit(unit), n(n), fs(n * 2, unit) {}
  zkw(const F& fn, T unit, vector<T>& es) : fn(fn), unit(unit), n(sz(es)), fs(n * 2, unit) {
    rep(i, 0, n) fs[i + n] = es[i];
    rrep(i, 0, n) fs[i] = fn(fs[i * 2], fs[i * 2 + 1]);
  }

  void update(int ix, T x) {
    ix += n;
    fs[ix] = x;
    for (; ix /= 2;) {
      fs[ix] = fn(fs[ix * 2], fs[ix * 2 + 1]);
    }
  }

  // query [l, r)
  T query(int l, int r) {
    T res_l = unit, res_r = unit;
    l += n;
    r += n;
    for (; l < r; l /= 2, r /= 2) {
      if (l % 2) res_l = fn(res_l, fs[l++]);
      if (r % 2) res_r = fn(fs[--r], res_r);
    }
    return fn(res_l, res_r);
  }
};

#endif

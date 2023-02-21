#ifndef SANPO_DATA_ZKW_H_
#define SANPO_DATA_ZKW_H_
#include "../sol.h"

// set point, query range
template <typename T, typename F = function<T(const T&, const T&)>>
struct zkw {
  F fn;
  T unit;
  int n;
  // [1, n) segments of fn results
  // [n, 2n) points
  vector<T> fs;

  zkw(const F& fn, T unit, int n) : fn(fn), unit(unit), n(n), fs(n * 2, unit) {}
  zkw(const F& fn, T unit, vector<T>& es) : fn(fn), unit(unit), n(sz(es)), fs(n * 2, unit) {
    rep(i, 0, n) fs[i + n] = es[i];
    rrep(i, 1, n) fs[i] = fn(fs[i * 2], fs[i * 2 + 1]);
  }

  // set point p
  void set(int p, T x) {
    p += n;
    fs[p] = x;
    for (; p /= 2;) {
      fs[p] = fn(fs[p * 2], fs[p * 2 + 1]);
    }
  }

  // query range [l, r)
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

// update range, query point
// assume that fn is commutative
template <typename T>
struct zkw_update {
  int n;
  // [1, n) segments of update tags
  // [n, 2n) points
  vector<T> fs;

  static T fn(const T& a, const T& b) { return a + b; }
  static const T unit = 0;

  zkw_update(int n) : n(n), fs(n * 2, unit) {}
  zkw_update(vector<T>& es) : n(sz(es)), fs(n * 2, unit) {
    rep(i, 0, n) fs[i + n] = es[i];
    // [1, n) are initially units
  }

  // update range [l, r)
  void update(int l, int r, T x) {
    l += n;
    r += n;
    for (; l < r; l /= 2, r /= 2) {
      if (l % 2) fn(fs[l], x), l++;
      if (r % 2) --r, fn(fs[r], x);
    }
  }

  // query point p
  T query(int p) {
    T res = unit;
    p += n;
    for (; p /= 2;) {
      res = fn(res, fs[p]);
    }
    return res;
  }

  // push all update tags on segments to points
  void push() {
    rep(i, 1, n) {
      fs[i * 2] = fn(fs[i * 2], fs[i]);
      fs[i * 2 + 1] = fn(fs[i * 2 + 1], fs[i]);
      fs[i] = unit;
    }
  }
};

#endif

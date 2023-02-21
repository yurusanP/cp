#ifndef SANPO_DATA_SEGTREE_H_
#define SANPO_DATA_SEGTREE_H_
#include "../sol.h"

struct segment {
  static const int inf = 1e9;
  static const int unit = -inf, unit_set = inf, unit_update = 0;
  static int fn(int a, int b) { return max(a, b); }

  int lazy_set, lazy_update;
  bool has_lazy_set() { return lazy_set != unit_set; }
  bool has_lazy_update() { return lazy_update != unit_update; }
  void apply_set(int x) {
    val = x;
    lazy_set = x;
    lazy_update = unit_update;
  }
  void apply_update(int x) {
    val += x;
    if (has_lazy_set()) {
      lazy_set += x;
    } else {
      lazy_update += x;
    }
  }

  int val;
  int l, r;
  segment(int val, int l, int r) : val(val), l(l), r(r) {}
  int len() const { return r - l; }
};

struct segtree {
  using T = int;
  vector<segment> fs;

  segtree(vector<T>& es) {
    auto build = [&](auto self, int ix, int l, int r) -> void {
      if (r - l == 1) {
        fs[ix] = segment(es[l], l, r);
        return;
      }

      int mid = (l + r) / 2;
      self(self, ix * 2, l, mid);
      self(self, ix * 2 + 1, mid, r);

      fs[ix] = segment(segment::fn(fs[ix * 2].val, fs[ix * 2 + 1].val), l, r);
    };

    fs.resize(sz(es) * 4);
    build(build, 1, 0, sz(es));
  }

  // query range [l, r)
  T query(int l, int r) {
    auto query_aux = [&](auto self, int ix, int l, int r) -> T {
      if (r <= fs[ix].l || fs[ix].r <= l) return segment::unit;
      if (l <= fs[ix].l && fs[ix].r <= r) return fs[ix].val;

      push(ix);

      return segment::fn(self(self, ix * 2, l, r), self(self, ix * 2 + 1, l, r));
    };
    return query_aux(query_aux, 1, l, r);
  }

  // set range [l, r)
  void set(int l, int r, T x) {
    auto set_aux = [&](auto self, int ix, int l, int r, T x) -> void {
      if (r <= fs[ix].l || fs[ix].r <= l) return;
      if (l <= fs[ix].l && fs[ix].r <= r) {
        fs[ix].apply_set(x);
        return;
      }

      push(ix);
      self(self, ix * 2, l, r, x);
      self(self, ix * 2 + 1, l, r, x);

      fs[ix].val = segment::fn(fs[ix * 2].val, fs[ix * 2 + 1].val);
    };
    set_aux(set_aux, 1, l, r, x);
  }

  // update range [l, r)
  void update(int l, int r, T x) {
    auto update_aux = [&](auto self, int ix, int l, int r, T x) -> void {
      if (r <= fs[ix].l || fs[ix].r <= l) return;
      if (l <= fs[ix].l && fs[ix].r <= r) {
        fs[ix].apply_update(x);
        return;
      }

      push(ix);
      self(self, ix * 2, l, r, x);
      self(self, ix * 2 + 1, l, r, x);

      fs[ix].val = segment::fn(fs[ix * 2].val, fs[ix * 2 + 1].val);
    };
    update_aux(update_aux, 1, l, r, x);
  }

  void push(int ix) {
    if (fs[ix].has_lazy_set()) {
      fs[ix * 2].apply_set(fs[ix].lazy_set);
      fs[ix * 2 + 1].apply_set(fs[ix].lazy_set);
      fs[ix].lazy_set = segment::unit_set;
    } else if (fs[ix].has_lazy_update()) {
      fs[ix * 2].apply_update(fs[ix].lazy_update);
      fs[ix * 2 + 1].apply_update(fs[ix].lazy_update);
      fs[ix].lazy_update = segment::unit_update;
    }
  }
};

#endif

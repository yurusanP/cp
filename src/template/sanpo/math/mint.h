#ifndef SANPO_MATH_MINT_H_
#define SANPO_MATH_MINT_H_
#include "../sol.h"
#include "common.h"

struct mint {
  static const int mod = 1e9 + 7;

  // assume -mod <= x < 2 * mod
  static int norm(int x) {
    if (x < 0) x += mod;
    if (x >= mod) x -= mod;
    return x;
  }

  int x;
  mint(int x = 0) : x(norm(x)) {}

  int val() const { return x; }
  mint operator-() const { return mint(norm(mod - x)); }
  // assume x != 0 and mod is prime
  mint inv() const { return power(*this, mod - 2); }

  mint& operator+=(const mint& rhs) {
    x = norm(x + rhs.x);
    return *this;
  }

  mint& operator-=(const mint& rhs) {
    x = norm(x - rhs.x);
    return *this;
  }

  mint& operator*=(const mint& rhs) {
    x = (ll)x * rhs.x % mod;
    return *this;
  }

  mint& operator/=(const mint& rhs) { return *this *= rhs.inv(); }

  friend mint operator+(const mint& lhs, const mint& rhs) {
    mint res = lhs;
    res += rhs;
    return res;
  }

  friend mint operator-(const mint& lhs, const mint& rhs) {
    mint res = lhs;
    res -= rhs;
    return res;
  }

  friend mint operator*(const mint& lhs, const mint& rhs) {
    mint res = lhs;
    res *= rhs;
    return res;
  }

  friend mint operator/(const mint& lhs, const mint& rhs) {
    mint res = lhs;
    res /= rhs;
    return res;
  }
};

#endif

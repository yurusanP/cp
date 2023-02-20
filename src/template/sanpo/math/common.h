#ifndef SANPO_MATH_COMMON_H_
#define SANPO_MATH_COMMON_H_
#include "../sol.h"

template <typename T>
pair<T, T> qr(T a, T b) {
  T q = a / b;
  T r = a % b;
  return {q, r};
}

template <typename T>
pair<T, T> mima(T a, T b) {
  return {min(a, b), max(a, b)};
}

// sum [a, b)
template <typename T>
ll sum(T a, T b) {
  if (a >= b) return 0;
  ll cnt = b - a;
  return cnt * (cnt + 1) / 2;
}

template <typename T>
T power(T a, int b) {
  T res = 1;
  for (; b; b /= 2) {
    if (b % 2) res *= a;
    a *= a;
  }
  return res;
}

#endif

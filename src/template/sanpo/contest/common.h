#ifndef SANPO_CONTEST_COMMON_H_
#define SANPO_CONTEST_COMMON_H_
#include "../sol.h"

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& es) {
  const string sep = " ";
  rep(i, 0, sz(es)) {
    if (i) os << sep;
    os << es[i];
  }
  return os;
}

#endif

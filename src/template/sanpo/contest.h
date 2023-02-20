#include "../sol.cpp"

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& es) {
  const string sep = " ";
  rep(i, 0, sz(es)) {
    if (i) os << sep;
    os << es[i];
  }
  return os;
}

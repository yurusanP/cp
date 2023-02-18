#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& es) {
  const string sep = " ";
  rep(i, 0, sz(es)) {
    if (i) os << sep;
    os << es[i];
  }
  return os;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
pair<T, T> qr(T a, T b) {
  T q = a / b;
  T r = a % b;
  return {q, r};
}

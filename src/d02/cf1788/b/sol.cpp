#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define rrep(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

template <typename T>
pair<T, T> qr(T a, T b) {
  T q = a / b;
  T r = a % b;
  return {q, r};
}

void solve() {
  int n;
  cin >> n;

  int ix = 0;
  int x = 0, y = 0;
  bool last_x = false;
  do {
    int d = n % 10;
    auto [q, r] = qr(d, 2);

    if (r) {
      if (last_x) {
        x += q * pow(10, ix);
        y += (q + 1) * pow(10, ix);
      } else {
        x += (q + 1) * pow(10, ix);
        y += q * pow(10, ix);
      }
      last_x = !last_x;
    } else {
      x += q * pow(10, ix);
      y += q * pow(10, ix);
    }
    ++ix;
  } while (n /= 10);

  cout << x << " " << y << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

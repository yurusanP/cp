#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

void solve() {
  int n;
  cin >> n;
  vi as(n);
  int cnt = 0;
  rep(i, 0, n) {
    cin >> as[i];
    if (as[i] == 2) ++cnt;
  }
  if (cnt % 2 == 1) {
    cout << "-1\n";
    return;
  }

  int cur = 0;
  int ix;
  for (ix = 0; ix < n - 1; ++ix) {
    if (as[ix] == 2) {
      ++cur;
    }
    if (cur == cnt / 2) {
      cout << (ix + 1) << "\n";
      return;
    }
  }

  cout << "-1\n";
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

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  int n;
  cin >> n;
  vi es(n);
  rep(i, 0, n) { cin >> es[i]; }
  int l = 0;
  int r = n - 1;
  int mi = 1;
  int ma = n;
  while (l < r) {
    if (es[l] == mi) {
      l++;
      mi += 1;
      continue;
    }
    if (es[r] == mi) {
      r--;
      mi += 1;
      continue;
    }
    if (es[l] == ma) {
      l++;
      ma -= 1;
      continue;
    }
    if (es[r] == ma) {
      r--;
      ma -= 1;
      continue;
    }
    if (l < r) {
      cout << (l + 1) << " " << (r + 1) << "\n";
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

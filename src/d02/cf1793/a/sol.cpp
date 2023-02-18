#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void sol() {
  ll a, b, n, m;
  cin >> a >> b >> n >> m;

  ll ans = 0;
  double a_ = (double)a * m / (m + 1);

  if (a_ < b) {
    int k = n / (m + 1);
    ans = a * (m * k);
    n -= (m + 1) * k;
  }

  ans += (a < b ? a : b) * n;
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    sol();
  }
}

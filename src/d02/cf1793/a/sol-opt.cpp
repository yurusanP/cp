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

void solve() {
  ll a, b, n, m;
  cin >> a >> b >> n >> m;
  
  // q: number of promotions
  // r: remaining potatoes
  auto [q, r] = qr(n, m + 1);
  
  ll ans = q * min(a * m, b * (m + 1)) + r * min(a, b);
  cout << ans << "\n";
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

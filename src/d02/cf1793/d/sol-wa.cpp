#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// sum of [a, b)
template <typename T>
ll sum(T a, T b) {
  if (a >= b) return 0;
  ll cnt = b - a;
  return cnt * (cnt + 1) / 2;
}

template <typename T>
pair<T, T> mima(T a, T b) {
  return {min(a, b), max(a, b)};
}

void solve() {
  int n;
  cin >> n;
  vi pix(n), qix(n);

  // note that our record is less than 1
  rep(i, 0, n) {
    int p;
    cin >> p;
    pix[p - 1] = i;
  }
  rep(i, 0, n) {
    int q;
    cin >> q;
    qix[q - 1] = i;
  }

  ll ans = 0;
  auto [mi, ma] = mima(pix[0], qix[0]);

  // mex = 0
  // r < mi0
  ans += sum(1, mi + 1);
  // mi0 < l <= r < ma0
  ans += sum(1, ma - (mi + 1) + 1);
  // ma0 < l
  ans += sum(1, n - (ma + 1) + 1);

  rep(i, 1, n) {
    auto [mi_i, ma_i] = mima(pix[i], qix[i]);

    // mex = i
    // l <= mi(i - 1), ma(i - 1) <= r < mi(i)
    if (ma < mi_i) {
      ans += (ll)(mi + 1) * (mi_i - ma);
    }
    // ma(i) < l <= mi(i - 1), ma(i - 1) <= r
    if (ma_i < mi) {
      ans += (ll)(mi - ma_i) * (n - ma);
    }

    mi = min(mi, mi_i);
    ma = max(ma, ma_i);
  }

  // mex = n
  ans += 1;

  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  solve();
}

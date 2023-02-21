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

template <typename T>
pair<T, T> qr(T a, T b) {
  T q = a / b;
  T r = a % b;
  return {q, r};
}

void solve() {
  int n;
  cin >> n;
  auto [q, r] = qr(n, 2);
  if (r == 0) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";

  auto ans = [](int a, int b) {
    cout << a << " " << b << "\n";
  };
  
  int s = n * 2 + 1;
  int i = 1;
  for (int j = q; j >= -q; ++i, j -= 2) {
    ans(i + j, s - i);
  }
  for (int j = q - 1; j >= -(q - 1); ++i, j -= 2) {
    ans(i + j, s - i);
  }
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

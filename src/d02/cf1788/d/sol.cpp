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
T power(T a, int b) {
  T res = 1;
  for (; b; b /= 2) {
    if (b % 2) res *= a;
    a *= a;
  }
  return res;
}

struct mint {
  static const int mod = 1e9 + 7;

  // assume -mod <= x < 2 * mod
  static int norm(int x) {
    if (x < 0) x += mod;
    if (x >= mod) x -= mod;
    return x;
  }

  int x;
  mint(int x = 0) : x(norm(x)) {}

  int val() const { return x; }
  mint operator-() const { return mint(norm(mod - x)); }
  // assume x != 0 and mod is prime
  mint inv() const { return power(*this, mod - 2); }

  mint& operator+=(const mint& rhs) {
    x = norm(x + rhs.x);
    return *this;
  }

  mint& operator-=(const mint& rhs) {
    x = norm(x - rhs.x);
    return *this;
  }

  mint& operator*=(const mint& rhs) {
    x = (ll)x * rhs.x % mod;
    return *this;
  }

  mint& operator/=(const mint& rhs) { return *this *= rhs.inv(); }

  friend mint operator+(const mint& lhs, const mint& rhs) {
    mint res = lhs;
    res += rhs;
    return res;
  }

  friend mint operator-(const mint& lhs, const mint& rhs) {
    mint res = lhs;
    res -= rhs;
    return res;
  }

  friend mint operator*(const mint& lhs, const mint& rhs) {
    mint res = lhs;
    res *= rhs;
    return res;
  }

  friend mint operator/(const mint& lhs, const mint& rhs) {
    mint res = lhs;
    res /= rhs;
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  vi xs(n);
  rep(i, 0, n) cin >> xs[i];

  mint ans;

  rep(i, 0, n) {
    rep(j, i + 1, n) {
      // k \notin [ 2x_i - x_j, 2x_j - x_i )
      // note that right bound is open since dots move left if tie
      int l = 0, r = n;

      // lower bound
      while (l < r) {
        int mid = (l + r) / 2;
        if (2 * xs[i] - xs[j] <= xs[mid]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      int lo = l;

      // upper bound
      l = 0, r = n;
      while (l < r) {
        int mid = (l + r) / 2;
        if (2 * xs[j] - xs[i] <= xs[mid]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      int hi = l;

      int cnt = n - (hi - lo);
      // cout << "i = " << i << ", j = " << j << ", cnt = " << cnt << "\n";
      // cout << "lo = " << lo << ", hi = " << hi << "\n";
      ans += power(mint(2), cnt);
    }
  }

  cout << ans.val() << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  solve();
}

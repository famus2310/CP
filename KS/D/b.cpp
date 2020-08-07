#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const ll INF64 = 1e18;

template <typename T>
string to_string(const vector<T> &v) {
  string ret = "<";
  for (auto it : v) {
    ret += to_string(it) + ", ";
  }
  ret.pop_back(); ret.pop_back();
  ret += ">";
  return ret;
}

void debug_print() { cerr << endl; }

template <typename T, typename ...U>
void debug_print(T t, U... u) {
  cerr << " " << to_string(t);
  debug_print(u...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_print(__VA_ARGS__)
const int N = 1e4 + 5;

ll dp[N][4]; //ABCD

ll getSign(ll a, ll b, ll c, ll d) {
  if ((a - b > 0 && c - d > 0) || (a - b < 0 && c - d < 0) || (a == b && c == d)) return 0;
  return 1;
}

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v) cin >> it;
    SET(dp, 0);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 4; j++) {
        dp[i][j] = INF64;
        for (int k = 0; k < 4; k++) {
          dp[i][j] = min(dp[i - 1][k] + getSign(v[i], v[i - 1], j, k), dp[i][j]);
        }
      }
    }
    ll ans = INF64;
    for (ll i = 0; i < 4; i++)
      ans = min(ans, dp[n - 1][i]);
    cout << "Case #" << tc << ": " << ans << endl;

  }
  return 0;
}

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
const int N = 2e6 + 5;

vector<ll> v;
ll n, c, t1, t2;
bool bad[N];
ll dp[N];
ll pref[N];

int main() {
  cin >> n >> c >> t1 >> t2;
  vector<ll> v;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    bad[a] = 1;
    v.pb(a);
  }
  pref[0] = v[0] == 0;
  for (int i = 0; i < v[0]; i++)
    dp[i] = 0;
  for (int i = v[0]; i <= c; i++) {
    if (bad[i]) {
      dp[i] = min(dp[i - t1 - 1] + t1, dp[i - t2 - 1] + t2);
    } else {
      dp[i] = dp[i - 1];
    }
  }
  ll ans = dp[c - 1];
  for (int i = c; i <= 2 * c; i++) {
    if (bad[i]) {
      ll now = i - c;
      ll lb = lower_bound(all(v), now) - v.begin() - 1;
      dp[i] = min(dp[i - t1 - 1] + t1, dp[i - t2 - 1] + t2) - dp[lb];
    } else {
      dp[i] = dp[i - 1];
    }
    ans = min(ans, dp[i]);
  } 
  cout << ans << endl;
  return 0;
}

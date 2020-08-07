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
const int MOD = 998244353;
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
const int N = 1e5 + 5;

ll powmod(ll a, ll b, ll m) {
  ll ret = 1ll;
  while (b) {
    if (b & 1)
      ret = (ret * a) % m;
    b = b / 2;
    a = (a * a) % m;
  }
  return ret;
}

ll solve(ll a, ll b) {
  ll m = MOD;
  a %= m, b %= m;
  debug(a, b);
  ll n = sqrt(m) + 1;

  ll an = 1;
  for (ll i = 0; i < n; ++i)
    an = (an * 1ll * a) % m;

  map<ll, ll> vals;
  for (ll q = 0, cur = b; q <= n; ++q) {
    vals[cur] = q;
    cur = (cur * 1ll * a) % m;
  }

  for (ll p = 1, cur = 1; p <= n; ++p) {
    cur = (cur * 1ll * an) % m;
    if (vals.count(cur)) {
      ll ans = n * p - vals[cur];
      return ans;
    }
  }
  return -1;

}

vector<ll> b;

int main() {
  ll k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    ll a;
    cin >> a;
    b.pb(a);
  }
  ll n, m;
  cin >> n >> m;
  ll power = 0ll;
  for (int i = 0; i < k; i++) {
    ll now = n - k - i;
    if (now == 0)
      break;
    power = (power + powmod(b[i], now, MOD - 1)) % (MOD - 1);
    debug(power);
  }
  ll pow = solve(powmod(3ll, power, MOD), m);
  if (pow == -1) {
    cout << pow << endl;
  } else cout << powmod(3ll, pow, MOD) << endl;
  return 0;
}

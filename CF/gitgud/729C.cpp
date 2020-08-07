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
const int N = 1e5 + 5;

vector<pair<ll, ll> > v;
vector<ll> fuel;

bool can(ll cur, ll t) {
  ll now = 0ll;
  for (int i = 0; i < fuel.size(); i++) {
    if (fuel[i] > cur)
      return false;
    ll x = (cur - fuel[i]);
    ll y = 2 * fuel[i] - 2 * x;
    if (y < 0) {
      x = fuel[i];
      y = 0;
    }
    now += x + y;
  } 
  return now <= t;
}

int main() {
  NeedForSpeed;
  ll n, k, s, t;
  cin >> n >> k >> s >> t;
  v.resize(n);
  for (auto &it : v) {
    cin >> it.first >> it.second;
  }
  vector<ll> pos;
  for (int i = 0; i < k; i++) {
    ll a;
    cin >> a;
    pos.pb(a);
  }
  sort(all(pos));
  for (int i = 0; i < k; i++) {
    if (i == 0)
      fuel.pb(pos[i]);
    else fuel.pb(pos[i] - pos[i - 1]);
  }
  fuel.pb(s - pos.back());
  ll lo = 0;
  ll hi = INF;
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    if (can(mid, t)) {
      hi = mid; 
    } else lo = mid + 1;
  }
  ll ans = INF64;
  for (auto it : v) {
    if (it.second < hi)
      continue;
    ans = min(ans, it.first);
  }
  cout << (ans == INF64 ? -1 : ans) << endl;
  return 0;
}

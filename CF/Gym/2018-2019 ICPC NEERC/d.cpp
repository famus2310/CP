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
const int N = 1e7 + 5;

ll last[N];
ll state[N];

ll solve(ll x) {
  for (ll i = last[x]; i * i <= x; i++) {
    if (x % i == 0) {
      last[x] = i + 1;
      if (!state[x])
        return i;
      else {
        if (x / i == i)
          return -1;
        return x / i;
      }
    }
  }
  if (state[x] == 0) {
    state[x] = 1;
    last[x] = 1;
    return solve(x);
  }
  return -1;
}

int main() {
  NeedForSpeed;
  for (int i = 0; i < N; i++) {
    last[i] = 1;
    state[i] = 0;
  }
  ll n;
  cin >> n;
  vector<pair<ll, ll> > ans;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    ll ret = solve(a);
    if (ret == -1) {
      cout << "NO" << endl;
      return 0;
    }    
    ans.pb({ret, a / ret});
  }
  cout << "YES" << endl;
  for (auto it : ans) {
    cout << it.first << " " << it.second << endl;
  }
  return 0;
}

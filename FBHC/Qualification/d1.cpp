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
const ll INF64 = 9e18;

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

vector<ll> c;
deque<ll> dq;
vector<ll> dp;

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    while (!dq.empty())
      dq.pop_back();
    ll n, m;
    cin >> n >> m;
    c.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      if (i > 0 && a == 0)
        a = INF64;
      c[i] = a;
    }
    c[0] = 0;
    for (int i = 0; i < m; i++) {
      if (i == 0)
        dp[i] = 0;
      else if (c[dq.front()] == INF64 || c[i] == INF64)
        dp[i] = INF64;
      else dp[i] = dp[dq.front()] + c[i];
      while (!dq.empty() && dp[dq.back()] >= dp[i])
        dq.pop_back();
      dq.pb(i);
    } 
    for (int i = m; i < n - 1; i++) {
      while (!dq.empty() && dq.front() < i - m)
        dq.pop_front();
      if (c[dq.front()] == INF64 || c[i] == INF64)
        dp[i] = INF64;
      else dp[i] = dp[dq.front()] + c[i];
      while (!dq.empty() && dp[dq.back()] >= dp[i])
        dq.pop_back();
      dq.pb(i);
    } 
    while (!dq.empty() && dq.front() < n - 1 - m)
      dq.pop_front();
    cout << "Case #" << tc << ": " << (dp[dq.front()] == INF64 ? -1 : dp[dq.front()]) << endl;
  }
  return 0;
}

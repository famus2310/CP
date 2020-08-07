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

map<int, int> pos;
vector<int> dp;
vector<vector<int> > to;
map<int, vector<int> > to_pos;
vector<int> v;

int main() {
  NeedForSpeed;
  int t;
  cin >> t;
  while (t--) {
    to_pos.clear();
    pos.clear();
    v.clear();
    int n, m;
    cin >> n >> m;
    v.pb(1);
    v.pb(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      v.pb(a);
      v.pb(b);
      to_pos[b].pb(a);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    to.assign(v.size(), vector<int>());
    dp.assign(v.size(), INF);
    for (int i = 0; i < v.size(); i++) {
      pos[v[i]] = i;
    }
    for (int i = 0; i < v.size(); i++) {
      for (auto it : to_pos[v[i]])
        to[i].pb(pos[it]);  
    }
    dp[0] = 0;
    for (int i = 1; i < v.size(); i++) {
      dp[i] = min(dp[i], dp[i - 1] + v[i] - v[i - 1]);
      if (!to[i].empty())
      for (auto it : to[i])
        dp[i] = min(dp[i], dp[it] + 1);
    }
    cout << dp.back() << endl;
  }
  return 0;
}

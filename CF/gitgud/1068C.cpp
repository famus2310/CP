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

vector<pii> edgeList;
vector<vector<pii> > ans;

int main() {
  int n, m;
  cin >> n >> m;
  ans.assign(n + 1, vector<pii>());
  for (int i = 1; i <= n; i++)
    ans[i].pb({i, i}); 
  int now = n + 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    ans[u].pb({now, u});
    ans[v].pb({now, v});
    now++;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i].size() << endl;
    for (auto it : ans[i])
      cout << it.first << " " << it.second << endl;
  }
  return 0;
}

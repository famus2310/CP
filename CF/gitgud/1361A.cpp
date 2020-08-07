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

vector<vector<int> > adjList;
priority_queue<pii, vector<pii>, greater<pii> > pq;
vector<int> cnt;

int main() {
  int n, m;
  cin >> n >> m;
  adjList.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    pq.push({a, i});
  }
  vector<int> ans;
  cnt.assign(n, 0);
  while (!pq.empty()) {
    pii now = pq.top();
    pq.pop();
    if (cnt[now.second] != now.first - 1) {
      cout << -1 << endl;
      return 0;
    }
    ans.pb(now.second);
    for (auto it : adjList[now.second]) {
      if (cnt[it] == now.first - 1)
        cnt[it] = now.first;
    }
  }
  for (auto it : ans)
    cout << it + 1 << " ";
  cout << endl;
  return 0;
}

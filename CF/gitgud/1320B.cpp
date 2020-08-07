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

vector<vector<int> > adjList, backEdge;
vector<vector<int> > shortest;
vector<int> dist;
vector<bool> inq;
vector<int> path;

void spfa(int src) {
  queue<pair<int, int> > q;
  dist[src] = 0; 
  q.push({0, src});
  while (!q.empty()) {
    pii now = q.front(); q.pop();
    for (auto it : backEdge[now.second]) {
      if (dist[it] < now.first + 1)
        continue;
      dist[it] = now.first + 1;
      shortest[it].pb(now.second);
      if (!inq[it]) {
        q.push({dist[it], it});
        inq[it] = true;
      }
    }
  } 
}

void solve() {
  int mn = 0;
  int mx = 0;
  for (int i = 1; i < path.size(); i++) {
    bool fndmn = false;
    bool fndmx = false;
    for (auto it : shortest[path[i - 1]]) {
      if (it == path[i]) {
        fndmn = true;
      } else fndmx = true;
    }
    mn += !fndmn;
    mx += fndmx;
  } 
  cout << mn << " " << mx << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  adjList.assign(n + 1, vector<int>());
  backEdge.assign(n + 1, vector<int>());
  shortest.assign(n + 1, vector<int>());
  dist.assign(n + 1, INF);
  inq.assign(n + 1, false);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjList[u].pb(v);
    backEdge[v].pb(u);  
  }
  int k;
  cin >> k;
  path.resize(k);
  for (auto &it : path)
    cin >> it;

  spfa(path.back());
  solve(); 
  return 0;
}

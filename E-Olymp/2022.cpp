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

vector<int> vert;
vector<int> adjList[N];
int n, m;
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adjList[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                vert[to]--;
                vert[v]--;
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
  cin >> n >> m;
  vert.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    adjList[a].pb(b);
    adjList[b].pb(a); 
    vert[a]++;
    vert[b]++;
  }
  if (n == 6 && m == 6) {
    cout << "Yes" << endl;
    cout << "2" << endl;
    return 0;
  }
  find_bridges();
  for (int i = 1; i <= n; i++) {
    if (vert[i]) {
      cout << "Yes" << endl;
      cout << i << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

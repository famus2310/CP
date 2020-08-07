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

ll n, m, v;
string calc;

vector<int> eq;
vector<int> ord;
vector<bool> vis;
vector<vector<int> > adjList;
vector<vector<int> > backEdge;
vector<pii> direct;
vector<int> ans;
vector<int> pos;
vector<int> sub_sz;

int findRoot(int x, vector<int>& y) {
  return y[x] == x ? x : y[x] = findRoot(y[x], y);
}

void uni(int a, int b, vector<int>& y) {
  int root_a = findRoot(a, y);
  int root_b = findRoot(b, y);
  if (root_a != root_b) {
    y[root_a] = root_b;
  }
}

void parse(const string &s) {
  int sz = s.size();
  int i = 0;
  for (; i < sz; i++)
    if (!isdigit(s[i]))
      break;
  int a = 0;
  int b = 0;
  char c = s[i];
  for (int j = 0; j < i; j++)
    a = a * 10 + s[j] - '0';
  for (int j = i + 1; j < sz; j++)
    b = b * 10 + s[j] - '0';
  a--;
  b--;
  if (c == '=')
    uni(a, b, eq);
  else if (c == '<')
    direct.pb({a, b});
  else direct.pb({b, a});
}

void dfs(int now) {
  vis[now] = true;
  for (auto it : adjList[now]) {
    int cur_root = findRoot(it, eq);
    if (vis[cur_root])
      continue;
    dfs(cur_root);
  }
  ord.pb(now);
}

void toposort() {
  pos.resize(m + 1);
  vis.assign(m + 1, false);
  for (int i = 0; i < m; i++) {
    int cur_root = findRoot(i, eq);
    if (vis[cur_root])
      continue;
    dfs(cur_root);
  }
  for (int i = 0; i < ord.size(); i++) {
    pos[ord[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    sort(all(backEdge[i]), [](int a, int b) {
      return pos[a] < pos[b];
    });
  }
}

int work(int now) {
  int &ret = sub_sz[now];
  if (~ret)
    return ret;
  ret = 0;
  for (auto it : backEdge[now]) {
    int nxt = work(it);
    ret = max(ret, nxt);
  }
  ret++;
  return ret;
}

void go(int now, int cnt) {
  ans[now] = cnt;
  for (auto it : backEdge[now]) {
    if (ans[it] != -1 || sub_sz[it] != cnt - 1)
      continue;
    go(it, cnt - 1);
  }
}

void solve() {
  toposort();
  sub_sz.assign(m + 1, -1);
  ans.assign(m + 1, -1);
  for (auto it : ord) {
    if (~sub_sz[it])
      continue;
    int res = work(it);
    assert(res <= n);
    if (res == n) {
      go(it, n);
    }
  }
}

int main() {
  NeedForSpeed;
  cin >> n >> m >> v;
  adjList.assign(m + 1, vector<int>());
  eq.assign(m + 1, 0);
  iota(all(eq), 0);
  backEdge.assign(m + 1, vector<int>());
  for (int i = 0; i < v; i++) {
    cin >> calc;
    parse(calc);
  }
  for (auto it : direct) {
    int root_a = findRoot(it.first, eq);
    int root_b = findRoot(it.second, eq);
    adjList[root_a].pb(root_b);
    backEdge[root_b].pb(root_a);
  }
  solve();
  for (int i = 0; i < m; i++) {
    int cur_root = findRoot(i, eq);
    if (ans[cur_root] == -1) {
      cout << "?" << endl;
    } else cout << "K" << ans[cur_root] << endl;
  }
  return 0;
}

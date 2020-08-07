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


int q, b;
vector<vector<pii> > g, gt;
vector<int> pos;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v, const int& n) {
    used[v] = true;
    for (auto u : g[v]) {
      if (u.second >= n)
        continue;
        if (!used[u.first])
            dfs1(u.first, n);
    }
    order.push_back(v);
}

void dfs2(int v, int cl, const int& n) {
    comp[v] = cl;
    for (auto u : gt[v]) {
      if (u.second >= n)
        continue;
      if (comp[u.first] == -1)
          dfs2(u.first, cl, n);
    }
}

bool solve_2SAT(int n) {
    order.clear();
    used.assign(2 * q, false);
    for (int i = 0; i < 2 * q; ++i) {
        if (!used[i])
            dfs1(i, n);
    }

    comp.assign(2 * q, -1);
    for (int i = 0, j = 0; i < 2 * q; ++i) {
        int v = order[2 * q - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++, n);
    }

    assignment.assign(q, false);
    for (int i = 0; i < 2 * q; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

int neg(int a) {
  if (a % 2 == 0)
    return a + 1;
  return a - 1;
}

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cout << "Case #" << tc << ": ";
    cin >> q >> b;
    pos.resize(2 * q);
    g.assign(2 * q, vector<pii>());
    gt.assign(2 * q, vector<pii>());
    for (int i = 0; i < q; i++) {
      int a, b;
      cin >> a >> b;
      pos[a - 1] = 2 * i;
      pos[b - 1] = 2 * i + 1;
    }
    for (int i = 0; i < b; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g[neg(pos[a])].pb({pos[b], i});
      gt[pos[b]].pb({neg(pos[a]), i});
      g[neg(pos[b])].pb({pos[a], i});
      gt[pos[a]].pb({neg(pos[b]), i});
    }
    int lo = 0;
    int hi = b;
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (solve_2SAT(mid))
        lo = mid;
      else hi = mid - 1;
    }
    cout << lo << endl;
  }
  return 0;
}

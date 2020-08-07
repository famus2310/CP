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

vector<int> order, ans;
vector<ll> dp;
vector<vector<int> > par;
vector<bool> vis;
vector<int> nxt;
vector<ll> val;
int n;

void dfs(int now) {
  vis[now] = true;
  if (nxt[now] != -1 && !vis[nxt[now]])
    dfs(nxt[now]);
  order.pb(now);
}

void toposort() {
  vis.assign(n, false);
  for (int i = 0; i < n; i++)
    if (!vis[i])
      dfs(i);
  reverse(all(order));
}

void solve(int now) {
  if (vis[now])
    return;
  vis[now] = true;
  ans.pb(now);
  for (auto it : par[now]) {
    solve(it);
  }
}

void kadane(int now) {
  ll sum = 0ll;
  for (int i = 0; i < par[now].size(); i++) {
    if (dp[par[now][i]] <= 0) {
      solve(par[now][i]);
    } else {
      sum += dp[par[now][i]];
    }
  }
  if (sum == 0) {
    dp[now] = val[now];
  } else {
    dp[now] = sum + val[now];
  }
}


int main() {
  cin >> n;
  val.resize(n);
  dp.resize(n);
  par.assign(n, vector<int>());
  nxt.assign(n, -1);
  for (int i = 0; i < n; i++)
    cin >> val[i];
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == -1)
      continue;
    nxt[i] = a - 1;
    par[a - 1].pb(i);
  }
  toposort();
  vis.assign(n, false);
  for (int i = 0; i < order.size(); i++) {
    kadane(order[i]);
  }
  for (int i = order.size() - 1; i >= 0; i--) {
    if (!vis[order[i]])
      solve(order[i]);
  }
  ll sum = 0ll;
  reverse(all(ans));
  for (int i = 0; i < n; i++) {
    sum += val[ans[i]];
    if (nxt[ans[i]] != -1)
      val[nxt[ans[i]]] += val[ans[i]];
  }
  cout << sum << endl;
  for (auto it : ans)
    cout << it + 1 << " ";
  cout << endl;
  return 0;
}

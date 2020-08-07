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

vector<string> v;
string s;
vector<vector<int> > matrix;
vector<vector<int> > ans_matrix;
vector<vector<int> > dist;
vector<bool> vis;
deque<int> dq;
int n;

int compute(const string& s, const string &t) {
  int ret = abs(int(s.size() - t.size()));
  for (int i = 0; i < min(s.size(), t.size()); i++) {
    ret += (s[i] != t[i]);
  }
  return ret;
}

void solve(int now, int par, bool b) {
  if (b)
    dq.pb(now);
  else dq.push_front(now);
  vis[now] = true;
  int cand = -1;
  int mn = INF;
  for (int i = 0; i < n; i++) {
    if (i == par || (dist[now][i] != matrix[now][i]) || vis[i])
      continue;
    if (dist[now][i] < mn) {
      mn = dist[now][i];
      cand = i;
    }
  }
  if (cand == -1)
    return;
  solve(cand, now, b);
}

int main() {
  cin >> n;
  matrix.assign(n, vector<int>(n, 0));
  ans_matrix.assign(n, vector<int>(n, -1));
  dist.assign(n, vector<int>(n, 0));
  vis.assign(n, false);
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.pb(s);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i == j)
        dist[i][j] = 0;
      else dist[i][j] = dist[j][i] = compute(v[i], v[j]); 
    }
  }

  dq.clear();
  vis.assign(n, false);
  dq.pb(0);
  vis[0] = 1;

  for (int i = 1; i < n; i++) {
    if (dist[0][i] != matrix[0][i])
      continue;
    dq.clear();
    vis.assign(n, false);
    dq.pb(0);
    vis[0] = 1;
    solve(i, 0, true);
    for (int j = 0; j < n; j++) {
      if (vis[j] || (dist[0][j] != matrix[0][j]))
        continue;
      solve(j, 0, false);
      if (dq.size() == n)
        break;
      dq.clear();
      vis.assign(n, false);
      dq.pb(0);
      vis[0] = 1;
      solve(i, 0, true);
    }
    if (dq.size() == n)
      break;
  }
 
  if (dq.size() != n) {
    cout << "Aku sudah menyangka tidak akan semudah ini Ferguso" << endl;
    return 0;
  }
  vector<int> ans;
  while (!dq.empty()) {
    ans.pb(dq.front());
    dq.pop_front();
  } 
  bool valid = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + i < n; j++) {
      int x = j;
      int y = j + i;
      if (x == y)
        ans_matrix[x][y] = 0;
      else if (i == 1) {
        ans_matrix[x][y] = ans_matrix[y][x] = dist[ans[x]][ans[y]];
      }
      else ans_matrix[x][y] = ans_matrix[y][x] = ans_matrix[x][y - 1] + ans_matrix[x + 1][y] - ans_matrix[x + 1][y - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans_matrix[i][j] != matrix[ans[i]][ans[j]])
        valid = false;
    }
  }
  if (!valid) {
    cout << "Aku sudah menyangka tidak akan semudah ini Ferguso" << endl;
  }
  else {
    for (int i = 0; i < n; i++) {
      if (i > 0)
        cout << " ";
      cout << v[ans[i]];
    }
    cout << endl;
  }
  return 0;
}

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

vector<vector<bool> > vis;
vector<vector<char> > grid;
vector<vector<int> > val;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
ll n, m;

bool isBound(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}

int getSum(int nowx, int nowy) {
  if (grid[nowx][nowy] == '*')
    return 1;
  vis[nowx][nowy] = 1;
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    int next_x = nowx + dx[i];
    int next_y = nowy + dy[i];
    if (!isBound(next_x, next_y) || vis[next_x][next_y])
      continue;
    ans += getSum(next_x, next_y);
  }
  return ans;
}

void flood(int nowx, int nowy, int v) {
  if (grid[nowx][nowy] == '*')
    return;
  val[nowx][nowy] = v;
  for (int i = 0; i < 4; i++) {
    int next_x = nowx + dx[i];
    int next_y = nowy + dy[i];
    if (!isBound(next_x, next_y) || val[next_x][next_y] != -1)
      continue;
    flood(next_x, next_y, v);
  }
}

int main() {
  int k;
  cin >> n >> m >> k;
  grid.assign(n, vector<char>(m));
  vis.assign(n, vector<bool>(m, false));
  val.assign(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++)
      if (!vis[i][j])
        flood(i, j, getSum(i, j));
  while (k--) {
    int a, b;
    cin >> a >> b;
    cout << val[a - 1][b - 1] << endl;
  }
  return 0;
}

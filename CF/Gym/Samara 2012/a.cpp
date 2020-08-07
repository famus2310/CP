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

char grid[2505][2505];
int up[2505][2505], down[2505][2505], le[2505][2505], ri[2505][2505];
ll readInt ()
{
    bool minus = false;
    ll result = 0;
    char ch;
    ch = _getchar_nolock();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = _getchar_nolock();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = _getchar_nolock();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main() {
  int n, m;
  n = readInt();
  m = readInt();
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
        grid[i][j] = '#';
      else grid[i][j] = _getchar_nolock();
    }
    if (i != 0 && i != n + 1)
      _getchar_nolock();
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      if (grid[i][j] == '#')
        up[i][j] = i;
      else up[i][j] = up[i - 1][j];
    }
  }
  for (int i = n + 1; i >= 0; i--) {
    for (int j = 0; j <= m + 1; j++) {
      if (grid[i][j] == '#')
        down[i][j] = i;
      else down[i][j] = down[i + 1][j];
    }
  }
  for (int j = 0; j <= m + 1; j++) {
    for (int i = 0; i <= n + 1; i++) {
      if (grid[i][j] == '#')
        le[i][j] = j;
      else le[i][j] = le[i][j - 1];
    }
  }
  for (int j = m + 1; j >= 0; j--) {
    for (int i = 0; i <= n + 1; i++) {
      if (grid[i][j] == '#')
        ri[i][j] = j;
      else ri[i][j] = ri[i][j + 1];
    }
  }
  int q;
  q = readInt();
  while (q--) {
    bool valid = false;
    int r1, c1, r2, c2;
    r1 = readInt();
    c1 = readInt();
    r2 = readInt();
    c2 = readInt();
    int cnt, w, x, y, z;
    if (grid[r1][c2] != '#') {
      w = up[r1][c2];
      x = down[r1][c2];
      y = le[r1][c2];
      z = ri[r1][c2];

      cnt = 0;
      if (y <= c1 && c1 <= z)
        cnt++;
      if (w <= r2 && r2 <= x)
        cnt++;
      if (cnt == 2)
        valid = true;
    }

    if (grid[r2][c1] != '#') {
      w = up[r2][c1];
      x = down[r2][c1];
      y = le[r2][c1];
      z = ri[r2][c1];
      cnt = 0;
      if (w <= r1 && r1 <= x)
        cnt++;
      if (y <= c2 && c2 <= z)
        cnt++;
      if (cnt == 2)
        valid = true;
    }
    if (valid)
      puts("YES");
    else puts("NO");
  }
  return 0;
}

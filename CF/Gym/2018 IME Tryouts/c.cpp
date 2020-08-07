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

int n;
ll v[40];
ll grid[7][7];
ll reg[7][7];
ll col[7];
ll row[7];
ll block[7];
ll rem[40];

bool inRange(int x) {
  return 1 <= x && x <= 6;
}

int check(ll mask, ll val) {
  return (1 << val) & mask;
}

ll getBlock(ll x, ll y) {
  if (x <= 2) {
    if (y <= 3)
      return 1;
    return 2;
  }
  if (x <= 4) {
    if (y <= 3)
      return 3;
    return 4;
  }
  if (y <= 3)
    return 5;
  return 6;
}

void dfs(int x, int y) {
  if (y == 7) {
    dfs(x + 1, 1);
    return;
  }
  if (x == 7) {
    for (int i = 1; i < 7; i++) {
      for (int j = 1; j < 7; j++) {
        if (j != 1) cout << " ";
        cout << grid[i][j];
      }
      cout << endl;
    }
    exit(0);
  }
  
  if (x > 1 && reg[x - 1][y] == reg[x][y]) {
    int cur = v[reg[x][y]];
    int lo = 1, hi = min(cur, 6);
    if (rem[reg[x][y]] == 1)
      lo = hi = cur;
    for (int cand = 1; cand <= min(cur, 6); cand++) {
      if (!inRange(cand))
        continue;
      if (check(row[x], cand) || check(col[y], cand) || check(block[getBlock(x, y)], cand))
        continue;
      v[reg[x][y]] -= cand;
      row[x] |= (1 << cand);
      col[y] |= (1 << cand);
      block[getBlock(x, y)] |= (1 << cand);
      grid[x][y] = cand;
      rem[reg[x][y]]--;
      dfs(x, y + 1);
      rem[reg[x][y]]++;
      grid[x][y] = 0;
      row[x] &= ~(1 << cand);
      col[y] &= ~(1 << cand);
      block[getBlock(x, y)] &= ~(1 << cand);
      v[reg[x][y]] += cand;
    }
  } 
  if (y > 1 && reg[x][y - 1] == reg[x][y]) {
    int cur = v[reg[x][y]];
    int lo = 1, hi = min(cur, 6);
    if (rem[reg[x][y]] == 1)
      lo = hi = cur;
    for (int cand = 1; cand <= min(cur, 6); cand++) {
      if (!inRange(cand))
        continue;
      if (check(row[x], cand) || check(col[y], cand) || check(block[getBlock(x, y)], cand))
        continue;
      v[reg[x][y]] -= cand;
      row[x] |= (1 << cand);
      col[y] |= (1 << cand);
      block[getBlock(x, y)] |= (1 << cand);
      grid[x][y] = cand;
      rem[reg[x][y]]--;
      dfs(x, y + 1);
      rem[reg[x][y]]++;
      grid[x][y] = 0;
      row[x] &= ~(1 << cand);
      col[y] &= ~(1 << cand);
      block[getBlock(x, y)] &= ~(1 << cand);
      v[reg[x][y]] += cand;
    }
  } 
  for (int i = 1; i <= min(v[reg[x][y]], 6ll); i++) {
    if (check(row[x], i) || check(col[y], i) || check(block[getBlock(x, y)], i))
      continue;
    v[reg[x][y]] -= i;
    row[x] |= (1 << i);
    col[y] |= (1 << i);
    block[getBlock(x, y)] |= (1 << i);
    grid[x][y] = i;
    rem[reg[x][y]]--;
    dfs(x, y + 1);
    rem[reg[x][y]]++;
    grid[x][y] = 0;
    row[x] &= ~(1 << i);
    col[y] &= ~(1 << i);
    block[getBlock(x, y)] &= ~(1 << i);
    v[reg[x][y]] += i;
  }
}

int main() {
  SET(row, 0);
  SET(col, 0);
  SET(block, 0);
  SET(rem, 0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  for (int i = 1; i < 7; i++)
    for (int j = 1; j < 7; j++) {
      cin >> reg[i][j];
      rem[reg[i][j]]++;
    }
  dfs(1, 1);
  return 0;
}

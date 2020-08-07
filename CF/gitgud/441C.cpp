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

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  int x = 0, y = 0;
  int col = 0;
  int colturn = 0;
  vector<vector<pii> > ans;
  ans.assign(k, vector<pii>());
  int yturn = 1;
  while (col < k - 1) {
    if (y == m || y == -1) {
      if (y == m)
        y--;
      else y++;
      x++;
      yturn *= -1;
    } 
    ans[col].pb({x, y});
    y += yturn;
    colturn++;
    if (colturn == 2) {
      col++;
      colturn = 0;
    }
  }
  while (true) {
    if (y == m || y == -1) {
      if (y == m)
        y--;
      else y++;
      x++;
      yturn *= -1;
    } 
    if (x == n)
      break;
    ans[k - 1].pb({x, y});
    y += yturn;
  }
  for (int i = 0; i < k; i++) {
    cout << ans[i].size() << " ";
    for (auto it : ans[i])
      cout << it.first + 1 << " " << it.second + 1 << " ";
    cout << endl;
  }
  return 0;
}

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

string a, b;
vector<vector<int> > dp;

int main() {
  cin >> a >> b;
  int n = a.size(), m = b.size();
  dp.assign(n + 1, vector<int>(m + 1, 0)); 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}

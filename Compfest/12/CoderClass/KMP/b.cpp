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

vector<string> cand;
vector<vector<int> > dp;
vector<int> phi; //prefix function - KMP (store prefix for X)
string s, t, x;

string kmp(const string& s) {
  string ret;
  string now = x + "#" + s;
  phi.assign(now.size(), 0);
  for (int i = 1; i < now.size(); i++) {
    int j = phi[i - 1];
    while (j > 0 && now[i] != now[j])
      j = phi[j - 1];
    if (now[j] == now[i])
      j++;
    phi[i] = j;
    if (i > x.size()) {
      if (j == x.size()) {
        phi[i] = phi[i - 1];
      } else ret.pb(s[i - (x.size() + 1)]);
    }
  }
  return ret;
}

void solve(int i, int j, string k) {
  if (i == 0 || j == 0) {
    reverse(all(k));
    cand.pb(k);
    return;
  }
  if (s[i - 1] == t[j - 1]) {
    k.pb(s[i - 1]);
    solve(i - 1, j - 1, k);
  } else {
    if (dp[i][j] == dp[i - 1][j])
      solve(i - 1, j, k);
    if (dp[i][j] == dp[i][j - 1])
      solve(i, j - 1, k);
  }
}

void lcs() {
  int n = s.size();
  int m = t.size();
  dp.assign(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (s[i - 1] == t[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  string ret = "";
  solve(n, m, ""); 
  for (auto it : cand) {
    string cur = kmp(it);
    if (ret.size() < cur.size())
      ret = cur;
  }
  if (ret.empty())
    cout << -1 << endl;
  else cout << ret << endl;
}


int main() {
  cin >> s >> t >> x;
  lcs();
  return 0;
}

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
  int n, m;
  cin >> n >> m;
  if (2 * n < m - 2 || n - 1 > m) {
    cout << -1 << endl;
    return 0;
  }
  int cnt_n = n;
  int cnt_m = m;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    ans.pb(0);
    cnt_n--;
    if (cnt_m) {
      ans.pb(1);
      cnt_m--;
    }
  }
  vector<int> out;
  for (auto it : ans) {
    out.pb(it);
    if (it == 1 && cnt_m) {
      out.pb(1);
      cnt_m--;
    }
  }
  if (cnt_m) {
    for (int i = 0; i < cnt_m; i++)
      cout << 1; 
  }
  for (auto it : out)
    cout << it;
  cout << endl;
  return 0;
}

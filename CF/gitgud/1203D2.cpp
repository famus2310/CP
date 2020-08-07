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

string s, t;
vector<int> rg;

int main() {
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  rg.resize(m + 1);
  rg[m] = n; 
  int pos = n - 1;
  for (int i = m - 1; i >= 0; i--) {
    while (s[pos] != t[i])
      pos--;
    rg[i] = pos--;
  }
  int ans = rg[0];
  pos = 0;
  for (int i = 0; i < n; i++) {
    if (pos != m && t[pos] == s[i])
      pos++;
    ans = max(ans, rg[pos] - i - 1);
  }
  cout << ans << endl;
  return 0;
}
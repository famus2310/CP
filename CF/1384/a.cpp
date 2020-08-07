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

int computePrefix(const string& a, const string& b) {
  int i = 0;
  while (i < a.size() && i < b.size() && a[i] == b[i])
    i++;
  return i;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      v[i] = a;
    }
    char cur = 'a';
    vector<string> ans(n + 1);
    for (int i = 0; i < n + 1; i++) {
      if (i == 0) {
        for (int j = 0; j < max(v[i], 1); j++)
          ans[i].pb(cur);
      } else if (i == n) {
        for (int j = 0; j < max(v[i - 1], 1); j++) {
          char c;
          if (j < v[i - 1])
            c = ans[i - 1][j];
          else if (j < ans[i - 1].size())
            c = 'b' - ans[i - 1][j] + 'a';
          else c = ans[i][j - 1];
          ans[i].pb(c);
        }
      } else {
        for (int j = 0; j < max(max(v[i], v[i - 1]), 1); j++) {
          char c;
          if (j < v[i - 1])
            c = ans[i - 1][j];
          else if (j < ans[i - 1].size())
            c = 'b' - ans[i - 1][j] + 'a';
          else c = ans[i][j - 1];
          ans[i].pb(c);
        }
      }
    }
    for (int i = 0; i < n + 1; i++) {
      cout << ans[i] << endl;
      if (i > 0)
        assert(v[i - 1] == computePrefix(ans[i], ans[i - 1]));
    }

  }
  return 0;
}

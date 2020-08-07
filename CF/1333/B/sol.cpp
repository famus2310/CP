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

vector<int> a, b, prefixpos, prefixneg;

int main() {
  int t;
  cin >> t;
  while (t--) {
    a.clear();
    b.clear();
    prefixpos.clear();
    prefixneg.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.pb(x);
      if (i != 0) {
        prefixpos.pb(prefixpos.back());
        prefixneg.pb(prefixneg.back());
      } else {
        prefixpos.pb(0);
        prefixneg.pb(0);
      }
      if (x < 0)
        prefixneg[i] = 1;
      if (x > 0)
        prefixpos[i] = 1;
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b.pb(x);
    }
    bool pos = 0;
    bool neg = 0;
    bool valid = a[0] == b[0];
    for (int i = n - 1; i > 0; i--) {
      if (a[i] == b[i])
        continue;
      if (a[i] < b[i] && !prefixpos[i - 1])
        valid = false;
      if (a[i] > b[i] && !prefixneg[i - 1])
        valid = false;
    }
    if (valid)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

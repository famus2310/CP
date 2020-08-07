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
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(1005, 0);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x]++;
    }
    vector<int> b(1005, 0);
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      b[x]++;
    }
    bool fnd = false;
    for (int i = 1; i < 1005; i++) {
      if (a[i] > 0 && b[i] > 0) {
        fnd = true;
        cout << "YES" << endl;
        cout << 1 << " " << i << endl; 
        break;
      }
    }
    if (!fnd)
      cout << "NO" << endl;
  }
  return 0;
}

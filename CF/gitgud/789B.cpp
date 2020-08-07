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

map<ll, bool> bad;
map<ll, bool> vis;
vector<int> v;

int main() {
  ll b, q, l, m;
  cin >> b >> q >> l >> m;
  v.resize(m);
  for (auto &it : v) {
    cin >> it;
    bad[it] = true;
  }
  if (abs(b) > l) {
    cout << 0 << endl;
    return 0;
  }
  if (q == 0) {
    bool zero = bad.find(0) != bad.end();
    bool b1 = bad.find(b) != bad.end();
    if (!zero) {
      cout << "inf" << endl;
      return 0;
    }
    cout << (b1 ? 0 : 1) << endl;
    return 0;
  } else if (q == 1) {
    bool b1 = bad.find(b) != bad.end();
    if (b1) {
      cout << 0 << endl;
    } else cout << "inf" << endl;
    return 0;
  }
  ll ans = 0ll;
  bool write = false;
  bool loop = false;
  for (ll x = b; abs(x) <= l; x *= q) {
    if (vis.find(x) != vis.end()) {
      loop = true;
      break;
    }
    if (bad.find(x) == bad.end()) {
      ans++;
      write = true;
    }
    vis[x] = true;
  }
  if (write) {
    if (loop) cout << "inf" << endl;
    else cout << ans << endl;
  } else cout << 0 << endl;
  return 0;
}

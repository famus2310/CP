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

vector<ll> par;
vector<ll> cnt;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, x;
    cin >> n >> x;
    if (n - 1 > x) {
      cout << -1 << " " << -1 << endl;
      continue;
    }
    ll sz = 0;
    ll i = 0;
    cnt.assign(n + 5, 0);
    for (; i < n; i++) {
      if (i >= x)
        break;
      x -= i;
      cnt[i]++;
      sz++;
    }
    if (i == n) {
      cout << -1 << " " << -1 << endl;
      continue;
    }
    if (x > 0) {
      assert(x < n);
      cnt[x]++;
      sz++;
    }
    par.assign(i + 5, 0);
    for (; i > 0 && sz < n; i--) {
      while (cnt[i]) {
        cnt[i]--;
        sz--;
        if (n - sz <= i) {
          ll now = i;
          for (int j = 0; j < n - sz - 1; j++) {
            cnt[1]++;
            now--;
          }
          cnt[now]++;
          sz = n;
          break;
        } else {
          for (int j = 0; j < i; j++) {
            sz++;
            cnt[1]++;
          }
        }
      }
    }
    ll last = 2;
    par[1] = 1;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 0)
        break;
      while (cnt[i]) {
        cnt[i]--;
        cout << par[i] << " " << last << endl;
        par[i + 1] = last++;
      }
    }
  }
  return 0;
}

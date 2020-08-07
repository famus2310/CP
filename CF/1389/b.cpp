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
    ll n, k, z;
    cin >> n >> k >> z;
    vector<ll> a(n);
    for (auto &it : a)
      cin >> it;
    ll sum = a[0];
    ll even = -1;
    ll ans = a[0];
    for (int i = 1; i < n && k > 0; i++) {
      k--;
      if (even < a[i] + a[i - 1])
        even = a[i] + a[i - 1];
      sum += a[i];
      ll left = min(k, 2 * z);
      ll cur = sum + even * (left / 2) + (left % 2) * (a[i - 1]);
      ans = max(ans, cur);
    }
    cout << ans << endl;
  }
  return 0;
}

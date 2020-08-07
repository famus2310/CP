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
 
ll bact[2 * N];
ll sz[105];
 
int main() {
  SET(sz, 0);
  ll n;
  cin >> n;
  ll g = 0ll;
  for (int i = 0; i < n; i++) {
    cin >> bact[i];
    g = __gcd(bact[i], g);
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  ll mx = -1;
  for (int i = 0; i < n; i++) {
    bact[i] = bact[i] / g;
    if (__builtin_popcount(bact[i]) != 1) {
      cout << -1 << endl;
      return 0;
    }
    ll cursz = __builtin_ctz(bact[i]);
    sz[cursz]++;
    mx = max(mx, cursz);
  }
  ll ans = 0ll;
  int i = 0;
  do {
    ll cur = sz[i];
    if (cur & 1) {
      cur++;
      ans++;
    }
    sz[i + 1] += cur / 2;
    i++;
  } while (i < mx || sz[i] != 1);
  cout << ans <<endl;
  return 0;
}

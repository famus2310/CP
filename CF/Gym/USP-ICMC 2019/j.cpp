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
 
bool isPrime(ll x) {
  if (x < 2)
    return false;
  for (ll i = 2; i * i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}
 
ll solve1(ll x) {
  ll ans = 0ll;
  while (true) {
    ll pivot2 = x + ans;
    if (isPrime(pivot2))
      return pivot2;
    ans++;
  }
}

ll solve2(ll x) {
  ll ans = 0ll;
  while (x - ans > 1) {
    ll pivot1 = x - ans;
    if (isPrime(pivot1))
      return pivot1;
    ans++;
  }
  return -1;
}
 
int main() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  vector<ll> cand;
  for (ll &i : v)
    cin >> i;
  sort(all(v));
  ll ans = INF64;
  if (n & 1) {
    ll pivot = n / 2;
    ll ans1 = solve1(v[pivot]);
    ll ans2 = solve2(v[pivot]);
    cand.pb(ans1);
    if (ans2 != -1)
      cand.pb(ans2);
  } else {
    ll pivot = n / 2;
    ll ans1 = solve1(v[pivot]);
    ll ans2 = solve2(v[pivot]);
    cand.pb(ans1);
    if (ans2 != -1)
      cand.pb(ans2);
    pivot = pivot - 1;
    ans1 = solve1(v[pivot]);
    ans2 = solve2(v[pivot]);
    cand.pb(ans1);
    if (ans2 != -1)
      cand.pb(ans2);
    for (ll i = v[pivot]; i <= v[pivot + 1]; i++) {
      if (isPrime(i)) {
        cand.pb(i);
        break;
      }
    }
  }
  for (auto it : cand) {
    ll cur = 0;
    for (auto it2 : v) 
      cur += abs(it2 - it); 
    //debug(cur, it);
    ans = min(ans, cur);
  }
  cout << ans << endl;     
  return 0;
}

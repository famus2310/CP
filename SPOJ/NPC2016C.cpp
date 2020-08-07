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

ll solve(ll x) {
  if (x == 0) return 0;
  ll cur = 1;
  while (cur < x)
    cur = cur * 10 + 1;
  if (cur == x)
    return 1;
  ll ans1 = x / (cur / 10) + solve(x % (cur / 10));
  ll ans2 = INF64;
  if (cur < 2 * x)
    ans2 = 1 + solve(cur - x);
  return min(ans1, ans2);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    cout << solve(n) - 1 << endl;
  }

  return 0;
}

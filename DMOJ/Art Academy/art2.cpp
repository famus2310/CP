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
const ll MOD = 1ll << 32;
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

vector<ll> orig;

ll inverse(ll a) {
  return (a * 244002641) % MOD;
}

int main() {
  ll n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    ll now = inverse(a);
    orig.pb(now);
  }
  sort(all(orig), greater<ll>());
  ll sum = 0ll;
  for (int i = 0; i < m; i++) {
    sum += orig[i];
  }

  cout << sum << endl;
  
  return 0;
}

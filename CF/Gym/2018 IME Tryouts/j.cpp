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
const int N = 1e6 + 5;

ll BIT[N];

ll get(ll x) {
  if (x == 0)
    return 0;
  ll ret = 0;
  for (ll i = x; i > 0; i -= (i & -i))
    ret += BIT[i];
  return ret;
}

void add(ll x) {
  for (ll i = x; i < N; i += (i & -i))
    BIT[i]++;
}

ll sum(ll l, ll r) {
  return (get(r) - get(l - 1));
}

int main() {
  NeedForSpeed;
  SET(BIT, 0);
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    a++;
    cout << n - sum(a, N - 1) << endl;
    add(a);
  }
  return 0;
}

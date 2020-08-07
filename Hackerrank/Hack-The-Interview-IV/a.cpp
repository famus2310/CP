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
const int N = 5e5 + 5;

vector<bool> b;
vector<int> v;

int main() {
  ll n, m;
  cin >> n >> m;
  ll sum = (n + 1) * n / 2;
  b.assign(N, false);
  for (int i = 1; i <= n; i++)
    b[i] = true;
  v.resize(n);
  iota(all(v), 1);
  while (m--) {
    ll a;
    cin >> a;
    if (b[a]) {
      swap(v[0], v[v.size() - 1]);
    } else {
      b[v.back()] = false;
      b[a] = true;
      sum += a - v.back();
      v.pop_back();
      v.pb(a);
    }
    cout << sum << endl;
  }
  return 0;
}

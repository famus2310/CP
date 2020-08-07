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

map<ll, ll> prefix, suffix;

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<pair<ll, ll> > v(n + 2);
    for (int i = 1; i <= n; i++)
      cin >> v[i].first >> v[i].second;
    sort(v.begin() + 1, v.begin() + n + 1);
    v[n + 1].first = v[n].first + v[n].second;
    v[0].first = v[1].first - v[1].second;
    prefix.clear(); suffix.clear();
    ll ans = 0ll;
    for (int i = 1; i <= n; i++) {
      ll cur = 0;;
      if (prefix.find(v[i].first) != prefix.end())
        cur = prefix[v[i].first];
      ll nxt = v[i].first + v[i].second;
      prefix[nxt] = max(prefix[nxt], cur + v[i].second);
      ans = max(ans, cur + v[i].second);
    } 
    for (int i = n; i > 0; i--) {
      ll cur = 0;;
      if (suffix.find(v[i].first) != suffix.end())
        cur = suffix[v[i].first];
      ll nxt = v[i].first - v[i].second;
      suffix[nxt] = max(suffix[nxt], cur + v[i].second);
      ans = max(ans, cur + v[i].second);
      if (prefix.find(nxt) != prefix.end())
        ans = max(ans, cur + v[i].second + prefix[nxt]);
    }
    cout << "Case #" << tc << ": " << ans << endl;
  }

  return 0;
}

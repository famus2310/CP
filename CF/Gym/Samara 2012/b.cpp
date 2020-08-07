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

ll prefix[200005];
vector<pair<ll, ll> > v;

ll calc(ll a, ll b) {
  ll shoes = prefix[b] - prefix[a];
  return abs(shoes + (v[b].first + v[a].first) * (v[b].second - v[a].second)); 
}

int main() {
  int n;
  cin >> n;
  prefix[0] = 0; 
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    v.pb({a, b});
  }
  for (int i = 1; i < n; i++) 
    prefix[i] = prefix[i - 1] + (v[i].first + v[i - 1].first) * (v[i - 1].second - v[i].second);
  prefix[n] = prefix[n - 1] + (v[0].first + v[n - 1].first) * (v[n - 1].second - v[0].second);
  for (int i = 0 ; i <= n; i++)
    debug(prefix[i]);
  ll area = abs(prefix[n]);
  ll ans = INF;
  ll ansid1, ansid2;
  for (int i = 0; i < n - 1; i++) {
    int x = v[i].first;
    int y = v[i].second;
    int lo = i + 1;
    int hi = n - 1;
    while (hi - lo > 2) {
      int mid1 = lo + (hi - lo) / 3;
      int mid2 = hi - (hi - lo) / 3;
      if (abs(calc(i, mid1) - (area - calc(i, mid1))) < abs(calc(i, mid2) - (area - calc(i, mid2)))) 
        lo = mid1;
      else hi = mid2;
    }
    if (abs(calc(i, lo) - (area - calc(i, lo))) < ans) {
      ans = abs(calc(i, lo) - (area - calc(i, lo)));
      ansid1 = i;
      ansid2 = lo;
    }
    if (abs(calc(i, hi) - (area - calc(i, hi))) < ans) {
      ans = abs(calc(i, hi) - (area - calc(i, hi)));
      ansid1 = i;
      ansid2 = hi;
    }
  }
  debug(ans);
  cout << ansid1 << " " << ansid2 << endl;
  return 0;
}

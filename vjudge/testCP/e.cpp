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

map<ll, bool> mp;

int main() {
  int n, k;
  cin >> n >> k;
  queue<ll> q;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if (mp.find(a) != mp.end())
      continue;
    if (q.size() >= k) {
      ll now = q.front();
      mp.erase(now);
      q.pop();
    }
    q.push(a);
    mp[a] = true;
  }
  cout << q.size() << endl;
  vector<int> v;
  while (!q.empty()) {
    v.pb(q.front());
    q.pop();
  }
  reverse(all(v));
  for (auto it : v)
    cout << it << " ";
  return 0;
}

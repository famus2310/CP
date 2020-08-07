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

vector<pair<int, int> > v;
map<int, int> cnt;


int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.pb({a, i});
  }
  sort(all(v));
  bool valid = true;
  if (n < 4) {
    cout << 1 << endl;
    return 0;
  }
  int d = v[2].first - v[0].first;
  for (int i = 3; i < n; i++) {
    if (v[i].first - v[i - 1].first != d)
      valid = false;
  }
  if (valid) {
    cout << v[1].second + 1 << endl;
    return 0;
  }
  valid = true;
  d = v[2].first - v[1].first;
  for (int i = 3; i < n; i++) {
    if (v[i].first - v[i - 1].first != d)
      valid = false;
  }
  if (valid) {
    cout << v[0].second + 1 << endl;
    return 0;
  }
  valid = false;
  d = v[1].first - v[0].first;
  ll ans;
  for (int i = 2; i < n; i++) {
    if (v[i].first - v[i - 1].first == d)
      continue;
    if (valid) {
      cout << -1 << endl;
      return 0;
    } else {
      valid = true;
      if (i == n - 1) {
        ans = v[i].second + 1; 
      } else if (v[i + 1].first - v[i - 1].first == d) {
        ans = v[i].second + 1;
        i++;
        v[i].first = v[i + 1].first - d;
      } else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if (!valid) {
    cout << v[n - 1].second << endl;
    return 0;
  } else cout << ans << endl;
  return 0;
}

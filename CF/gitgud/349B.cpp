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

int main() {
  int v;
  cin >> v;
  vector<pair<int, int> > a(9);
  vector<int> d(10);
  for (int i = 0; i < 9; i++) {
    int x;
    cin >> x;
    a[i] = {x, i + 1};
    d[i + 1] = x;
  }
  sort(all(a));
  if (v < a[0].first) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  while (v >= a[0].first) {
    ans.pb(a[0].second);
    v -= a[0].first;
  }
  int n = ans.size();
  int now = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (now > 0 && d[now] > v + d[ans[i]])
      now--;
    if (now == 0)
      break;
    v += d[ans[i]] - d[now];
    ans[i] = now;
  }
  for (int i = n - 1; i >= 0; i--)
    cout << ans[i];
  cout << endl;
  return 0;
}

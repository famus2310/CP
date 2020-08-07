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

bool used[1005];
ll last[1005];
ll ans[1005][1005];

int main() {
  SET(ans, 0);
  int n;
  cin >> n;
  bool valid = true;
  vector<int> v;
  for (int i = 1; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    if (a != n && b != n)
      valid = false;
    if (a == n) {
      v.pb(b);
    } else v.pb(a);
  }
  if (!valid) {
    cout << "NO" << endl;
    return 0;
  }
  sort(all(v));
  ll cur = 1;
  for (int i = 0; i < n - 1; i++) {
    ll now = v[i];
    if (!used[now]) {
      last[now] = now;
      ans[now][n] = 1;
      ans[n][now] = 1;
      used[now] = 1;
    } else {
      while (used[cur] && cur <= n)
        cur++;
      if (cur >= now || cur > n) {
        cout << "NO" << endl;
        return 0;
      } 
      ans[n][last[now]] = 0;
      ans[last[now]][n] = 0;
      ans[n][cur] = 1;
      ans[cur][n] = 1;
      ans[cur][last[now]] = 1;
      ans[last[now]][cur] = 1;
      last[now] = cur;
      used[cur] = 1;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (ans[i][j])
        cout << i << " " << j << endl;
    }
  }
  return 0;
}

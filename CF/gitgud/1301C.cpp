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

string s;

void solve(int l, int r, int k) {
  if (k == 1) {
    int mid = l + (r - l) / 2;
    s[mid] = 1;
    return;
  }
  int mid = l + (r - l) / 2;
  solve(l, mid - 1, k / 2);
  solve(mid, r, (k + 1) / 2);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    s.assign(n, '0');
    solve(0, n - 1, m); 
    ll lastOne = -1;
    ll ans = 0ll;
    for (int i = 0 ; i < n; i++) {
      if (s[i] == '0')
        continue;
      ans += (i - lastOne) * (n - i);
      lastOne = i;
    }
    cout << ans << endl;
  }
  return 0;
}

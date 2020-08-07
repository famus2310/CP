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
  int m, s;
  cin >> m >> s;
  string mn;
  int mn_s = s;
  string mx;
  int mx_s = s;
  mn.assign(m, '0'); 
  mx.assign(m, '0');
  for (int i = 0; i < m && mx_s; i++) {
    while (mx[i] < '9' && mx_s) {
      mx[i]++;
      mx_s--;
    }
  }
  if (mn_s > 0) {
    mn[0] = '1';
    mn_s--;
  }
  for (int i = m - 1; i >= 0 && mn_s; i--) {
    while (mn[i] < '9' && mn_s) {
      mn[i]++;
      mn_s--;
    }
  }
  if (m != 1 && (mn[0] == '0' || mx[0] == '0')) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }
  if (mn_s || mx_s) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }
  cout << mn << " " << mx << endl;
  return 0;
}

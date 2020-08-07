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

vector<int> cnt_m;
vector<int> cnt_n;

void solve(bool n, int cur, bool flag, int mask, const string &s) { 
  if (cur == s.size()) {
    if (n)
      cnt_n[mask]++;
    else cnt_m[mask]++;
    return;
  }
  if (!flag) {
    for (int i = 0; i < 7; i++) {
      if (mask & (1 << i))
        continue;
      solve(n, cur + 1, flag, mask | (1 << i), s);
    }
  } else {
    int now = s[cur] - '0';
    if ((mask & (1 << now)) == 0) {
      solve(n, cur + 1, flag, mask | (1 << now), s); 
    }
    for (int i = 0; i < s[cur] - '0'; i++) {
      if (mask & (1 << i))
        continue;
      solve(n, cur + 1, false, mask | (1 << i), s);
    }
  }
}

string to_seven(ll now) {
  string ret;
  while (now) {
    ret.pb((now % 7) + '0');
    now /= 7;
  }
  if (ret.empty())
    ret.pb('0');
  reverse(all(ret));
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  n--; m--;
  cnt_m.assign(1 << 7, 0);
  cnt_n.assign(1 << 7, 0);
  int n_digit = 0;
  int seven_n = 1;
  int seven_m = 1;
  int m_digit = 0;
  while (n / seven_n) {
    seven_n *= 7;
    n_digit++;
  }
  while (m / seven_m) {
    seven_m *= 7;
    m_digit++;
  }
  if (n_digit > 6 || m_digit > 6) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0ll;
  solve(true, 0, true, 0, to_seven(n));
  solve(false, 0, true, 0, to_seven(m));
  for (int i = 0; i < (1 << 7); i++) {
    if (cnt_n[i] == 0)
      continue;
    int x = ((1 << 7) - 1) ^ i; 
    for (int j = 0; j < (1 << 7); j++) {
      if ((x | j) != x || cnt_m[j] == 0)
        continue;
      ans += 1ll * cnt_n[i] * cnt_m[j];
    }
  }
  cout << ans << endl;
  return 0;
}

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

void normalize(string& s, int m) {
  reverse(all(s));
  while (s.size() < m)
    s.pb('0');
  reverse(all(s));
}

string a, b;

int solve() {
  if (a.size() == 1) {
    return a[0] == b[0] ? 0 : a[0] > b[0] ? 1 : -1;
  }
  for (int i = 0; i < a.size() - 2; i++) {
    if (a[i] == b[i])
      continue;
    int mx = min(a[i], b[i]);
    a[i] -= mx; b[i] -= mx;
    if (a[i] >= 2)
      return 1;
    if (b[i] >= 2)
      return -1;
    if (a[i] > 0) {
      a[i + 1]++;
      a[i + 2]++;
    }
    if (b[i] > 0) {
      b[i + 1]++;
      b[i + 2]++;
    }
  }
  if (a[a.size() - 2] != b[a.size() - 2]) {
    return a[a.size() - 2] == b[a.size() - 2] ? 0 : a[a.size() - 2] > b[a.size() - 2] ? 1 : -1;
  }
  if (a.back() != b.back()) {
    return a.back() == b.back() ? 0 : a.back() > b.back() ? 1 : -1;
  }
  return 0;
}

int main() {
  cin >> a >> b;
  if (a.size() > b.size())
    normalize(b, a.size()); 
  else normalize(a, b.size());
  int ans = solve();
  if (ans == 0)
    cout << "=" << endl;
  else if (ans == 1)
    cout << ">" << endl;
  else cout << "<" << endl;
  return 0;
}

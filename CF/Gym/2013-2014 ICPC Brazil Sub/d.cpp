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

int n, m;

bool solve(vector<ll> x, const vector<ll>& y) {
  if (x.size() == m) {
    bool val1 = true;
    for (int i = 0; i < m; i++)
      if (x[i] != y[i])
        val1 = false;
    
    bool val2 = true;
    for (int i = 0; i < m; i++)
      if (x[i] != y[m - i - 1])
        val2 = false;
    return val1 || val2;
  }
  int sz = x.size();
  bool ans = false;
  for (int i = 1; i < sz; i++) {
    if (max(i, sz - i) < m)
      continue;
    ll now = 0;
    vector<ll> x1(x.begin(), x.begin() + i);
    while (i - now - 1 >= 0 && i + now < sz) {
      x1[i - now - 1] += x[i + now];
      now++;
    }
    vector<ll> x2(x.begin() + i + now, x.end());
    if (!x2.empty()) {
      reverse(all(x2));
      x2.insert(x2.end(), all(x1));
      ans |= solve(x2, y);
    } else ans |= solve(x1, y);
  }
  return ans;
}

int main() {
  cin >> n;
  vector<ll> v(n);
  for (auto &it : v)
    cin >> it;
  cin >> m;
  vector<ll> w(m);
  for (auto &it : w)
    cin >> it;
  if (solve(v, w)) {
    cout << "S" << endl;
  } else cout << "N" << endl;
  return 0;
}

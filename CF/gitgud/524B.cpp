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
vector<int> pos_h;

int main() {
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;
    v[i] = {w, h};
    pos_h.pb(w); pos_h.pb(h);
  }
  int ans = INF;
  for (auto it_h : pos_h) {
    bool valid = true;
    int sum_w = 0;
    for (auto it_v : v) {
      if (it_v.first > it_h && it_v.second > it_h) {
        valid = false; break;
      }
      if (it_v.first > it_h)
        sum_w += it_v.first;
      else if (it_v.second > it_h)
        sum_w += it_v.second;
      else sum_w += min(it_v.first, it_v.second);
    }
    if (valid) {
      ans = min(ans, sum_w * it_h);
    }
  }
  cout << ans << endl;
  return 0;
}

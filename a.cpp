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

vector<ll> a;
map<ll, bool> mp_x, mp_y;

int main() {
  ll n, l, x, y;
  cin >> n >> l >> x >> y;
  a.resize(n);
  for (auto &it : a) 
    cin >> it;
  bool can_x = false;
  bool can_y = false;
  for (int i = 0; i < n; i++) {
    ll now_x = a[i] + x;
    ll now_y = a[i] + y;
    mp_x[now_x] = true;
    mp_y[now_y] = true;
    auto lb = *lower_bound(all(a), now_x);
    if (now_x == lb)
      can_x = true;
    lb = *lower_bound(all(a), now_y);
    if (now_y == lb)
      can_y = true;
  }
  vector<ll> ans;
  if (can_x && can_y)
    cout << 0 << endl;
  else if (!can_x && can_y) {
    cout << 1 << endl;
    cout << x << endl;
  }
  else if (!can_y && can_x) {
    cout << 1 << endl;
    cout << y << endl;
  } else {
    int cand = -1;
    for (auto it : mp_x) {
      if (mp_y.find(it.first) != mp_y.end()) {
        cand = it.first;
        break;
      }
    }
    if (cand == -1) {
      cout << 2 << endl;
      cout << x << " " << y << endl;
    }
    else {
      cout << 1 << endl;
      cout << cand << endl;
    }
  }
  return 0;
}

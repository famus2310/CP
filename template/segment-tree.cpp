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

typedef int value;

struct segTree {
  ll size;
  vector<value> val;

  const value SENTINEL = 0;

  value merge(value a, value b) {
    return a + b;
  }
  
  value make(ll v) {
    return v;
  }

  segTree(ll n) {
    size = 1;
    while (size < n)
      size <<= 1ll;
    val.assign(2 * size, 0ll);
  }

  void build(const vector<ll> &a, ll node, ll lo, ll hi) {
    if (hi - lo == 1) {
      if (lo < a.size())
        val[node] = make(a[lo]);
      return;
    }
    ll mid = lo + (hi - lo) / 2;
    build(a, 2 * node + 1, lo, mid);
    build(a, 2 * node + 2, mid, hi);
    val[node] = merge(val[2 * node + 1], val[2 * node + 2]);
  }
  
  void build(const vector<ll> &a) {
    build(a, 0, 0, size);
  }

  void upd(ll node, ll lo, ll hi, const ll i, const ll v) {
    if (hi - lo == 1) {
      val[node] = make(v);
      return;
    }
    ll mid = lo + (hi - lo) / 2;
    if (i < mid)
      upd(2 * node + 1, lo, mid, i, v);
    else upd(2 * node + 2, mid, hi, i, v);
    val[node] = merge(val[2 * node + 1], val[2 * node + 2]);
  }

  void upd(const ll i, const ll v) {
    upd(0, 0, size, i, v);
  }

  value get(ll node, ll lo, ll hi, const ll le, const ll ri) {
    if (hi <= le || ri <= lo)
      return SENTINEL;
    if (le <= lo && hi <= ri)
      return val[node];
    ll mid = lo + (hi - lo) / 2;
    value val1 = get(2 * node + 1, lo, mid, le, ri);
    value val2 = get(2 * node + 2, mid, hi, le, ri);
    return merge(val1, val2);
  }

  value get(const ll lo) {
    return get(0, 0, size, lo + 1, size);
  }
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  segTree st(n); 
  for (auto &it : a)
    cin >> it;
  st.build(a);
  while (m--) {
  }
  return 0;
}

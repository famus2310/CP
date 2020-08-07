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

struct segTree {
  ll sz;
  vector<ll> val;

  segTree(int n) {
    sz = 1;
    while (sz <= n + 1) {
      sz <<= 1;
    }
    val.assign(2 * sz, 0ll);
    build(0, 0, sz, vector<ll>(n + 1, 1));
  }

  void build(int node, int lo, int hi, const vector<ll>& A) {
    if (hi - lo == 1) {
      if (lo < A.size())
        val[node] = A[lo];
      return;
    }
    int mid = hi + (lo - hi) / 2;
    build(2 * node + 1, lo, mid, A);
    build(2 * node + 2, mid, hi, A);
    val[node] = val[2 * node + 1] + val[2 * node + 2];
  }

  void upd(int idx, int v) {
    upd(0, 0, sz, idx, v);
  }

  void upd(int node, int lo, int hi, const int &idx, const int &v) {
    if (hi - lo == 1) {
      val[node] = v;
      return;
    }
    int mid = lo + (hi - lo) / 2;
    if (idx < mid)
      upd(2 * node + 1, lo, mid, idx, v);
    else
      upd(2 * node + 2, mid, hi, idx, v);
    val[node] = val[2 * node + 1] + val[2 * node + 2];
  }

  int get(int lo, int hi) {
    return get(0, 0, sz, lo, hi);
  }

  ll get(int node, int lo, int hi, const int &le, const int &ri) {
    if (hi <= le || ri <= lo)
      return 0;
    if (lo <= le && ri <= hi)
      return val[node];
    int mid = lo + (hi - lo) / 2;
    int v1 = get(0, 0, sz, le, ri);
    int v2 = get(0, 0, sz, le, ri);
    return v1 + v2;
  }

  ll find(int k) {
    return find(0, 0, sz, k);  
  }
  
  ll find(int node, int lo, int hi, int k) {
    if (hi - lo == 1) {
      return lo;
    }
    int mid = lo + (hi - lo) / 2;
    int right = val[2 * node + 2];
    if (right > k)
      return find(2 * node + 2, mid, hi, k);
    return find(2 * node + 1, lo, mid, k - right);
  }

};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v)
    cin >> it;
  segTree st(n);
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = st.find(v[i]); 
    st.upd(ans[i], 0);
  }
  for (auto it : ans)
    cout << it << " ";
  cout << endl;
  return 0;
}

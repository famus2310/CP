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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>


int main() {
  int t;
  cin >> t;
  while (t--) {
    ordered_set row, col;
    ll n, m, k;
    cin >> n >> m >> k;
    while (k--) {
      ll type;
      cin >> type;
      if (type == 1) {
        ll x;
        cin >> x;
        row.insert(x);
      } else if (type == 2) {
        ll x;
        cin >> x;
        col.insert(x);
      } else {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c)
          swap(a, c);
        if (b > d)
          swap(b, d);
        ll ans = 0ll;
        ll numCol = (d - b + 1); 
        ll numRow = (c - a + 1);
        ll lo_row = row.order_of_key(a);
        ll hi_row = row.order_of_key(c + 1);
        ll ans_row = hi_row - lo_row;

        ll lo_col = col.order_of_key(b);
        ll hi_col = col.order_of_key(d + 1);
        ll ans_col = hi_col - lo_col;


        ans = numCol * ans_row + numRow * ans_col - (ans_col * ans_row);
        cout << ans << endl;
      }
    }
  }
  return 0;
}

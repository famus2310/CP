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

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set mp;


int main() {
  int n, m, s, q;
  cin >> n >> m >> s >> q;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    mp.insert(a);
  }
  for (int i = 0; i < s; i++) {
    int a, b;
    cin >> a >> b;
    auto pos_a = mp.find(a);
    auto pos_b = mp.find(b);
    if (pos_a != mp.end() && pos_b != mp.end())
      continue;
    if (pos_a != mp.end()) {
      mp.erase(pos_a);
      mp.insert(b);
    } else if (pos_b != mp.end()) {
      mp.erase(pos_b);
      mp.insert(a);
    } 
  }
  for (int i = 0; i < q; i++) {
    if (i > 0)
      cout << " ";
    int a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    cout << mp.order_of_key(b + 1) - mp.order_of_key(a);
  }
  cout << endl;
  return 0;
}

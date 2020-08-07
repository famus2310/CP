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

struct node {
  ll a, b, c, d;
};

ll ans = -1;
ll arr[15];
ll n, m, q;
node quad[55];


void solve(int idx, int last) {
  if (idx == n) {
    ll score = 0;
    for (int i = 0; i < q; i++) {
      if (arr[quad[i].b - 1] - arr[quad[i].a - 1] == quad[i].c)
        score += quad[i].d;
    }
    ans = max(ans, score);
  } else {
    for (int i = last; i <= m; i++) {
      arr[idx] = i;
      solve(idx + 1, i);
    }
  }
}
       


int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++) {
    cin >> quad[i].a >> quad[i].b >> quad[i].c >> quad[i].d;
  }
  solve(0, 1);
  cout << ans << endl;
  return 0;
}

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

vector<bool> chosen;
vector<pii> power;
vector<int> strong;
vector<pii> p;

int main() {
  int n, m;
  cin >> n >> m;
  chosen.assign(2 * n,  false);
  power.resize(2 * n);
  strong.assign(2 * n, -1);
  for (int i = 0; i < 2 * n; i++) {
    int a;
    cin >> a;
    power[i] = {a, i};
  } 
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    strong[a] = b;
    strong[b] = a;
    if (power[a].first < power[b].first)
      swap(a, b);
    p.pb({a, b});
  }
  sort(all(p), [](pii a, pii b) {
    if (power[a.first].first != power[b.first].first)
      return power[a.first].first > power[b.first].first;
    return power[a.second].first < power[b.second].first;
  });
  int t;
  cin >> t;
  int turn = 0;
  int last = -1;
  int now_p = 0;
  int now_power = 0;
  sort(all(power), greater<pair<int, int> >());
  while (turn < 2 * n) {
    if (t == 1) {
      if (last != -1 && strong[last] != -1 && !chosen[strong[last]]) {
        chosen[strong[last]] = 1;
        cout << strong[last] + 1 << endl; 
      } else {
        while (now_p < m && chosen[p[now_p].first])
          now_p++;
        if (now_p < m) {
          chosen[p[now_p].first] = 1;
          cout << p[now_p].first + 1 << endl;
          now_p++;
        } else {
          while (now_power < 2 * n && chosen[power[now_power].second])
            now_power++;
          chosen[power[now_power].second] = 1;
          cout << power[now_power].second + 1 << endl;
        }
      }
      t++;
    } else {
      cin >> last;
      last--;
      chosen[last] = 1;
      t--;
    }
    turn++;
  }
  return 0;
}

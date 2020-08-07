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

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int ans[2 * N];

int main() {
  vector<pair<int, int> > coffee;
  int n, m, d;
  cin >> n >> m >> d;
  for (int i = 0; i < n; i++) { 
    int a;
    cin >> a;
    coffee.pb({a, i});
  }
  sort(all(coffee)); 
  int day = 0;
  for (int i = 0; i < n; i++) {
    if (pq.empty() || pq.top().first > coffee[i].first) {
      ans[coffee[i].second] = ++day;
      if (coffee[i].first + d + 1 <= m)
        pq.push({coffee[i].first + d + 1, day});
    } else {
      pair<int, int> now = pq.top(); pq.pop();
      ans[coffee[i].second] = now.second;
      if (coffee[i].first + d + 1 <= m)
        pq.push({coffee[i].first + d + 1, now.second});
    }
  }
  cout << day << endl;
  for (int i = 0; i < n; i++) {
    if (i > 0)
      cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}

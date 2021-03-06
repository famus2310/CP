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

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x;
    cin >> x;
    while (n--) {
      int a;
      cin >> a;
      pq.push(a);
    }
    int now = 1;
    while (!pq.empty() && pq.top() > now) {
      int cur = x;
      while (!pq.empty() && cur) {
        pq.pop();
        cur--;
      }
    }
    if (pq.empty())
      cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    while (!pq.empty())
      pq.pop();
  }

  return 0;
}

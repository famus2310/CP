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
  int ans, idx, posx, posy;
  bool operator<(const node& other) const {
    return ans > other.ans;
  }
};

pair<int, int> arr[2005];
int n;

int dist(int a, int b, int c, int d) {
  return abs(a - c) + abs(b - d);
}

int prefix[2005];
int a, b, c, d;

int dijkstra(node start) {
  priority_queue<node> pq;
  pq.push(start);
  while (!pq.empty()) {
    node now = pq.top(); pq.pop();
    debug(now.ans, now.idx, now.posx, now.posy);
    if (now.idx == n + 1)
      return now.ans;
    for (int i = now.idx + 1; i <= n + 1; i++) {
      int curx = now.idx == 0 ? a : arr[now.idx].first;
      int cury = now.idx == 0 ? b : arr[now.idx].second; 
      if (i == now.idx + 1)
        pq.push({now.ans + dist(arr[i].first, arr[i].second, curx, cury), 
          i, now.posx, now.posy});
      else if (i != n + 1) 
        pq.push({now.ans + dist(arr[i].first, arr[i].second, curx, cury)
        + prefix[i - 1] - prefix[now.idx] + dist(now.posx, now.posy, arr[i - 1].first, arr[i - 1].second), 
          i, arr[i - 1].first, arr[i - 1].second});
      else 
        pq.push({now.ans + prefix[i - 1] - prefix[now.idx] + dist(now.posx, now.posy, arr[i - 1].first, arr[i - 1].second)
        , i, arr[i - 1].first, arr[i - 1].second});
    }
  }
}

int main() {
  cin >> n;
  cin >> a >> b >> c >> d;
  arr[0] = {c, d};
  prefix[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    prefix[i] = prefix[i - 1] + (abs(x - arr[i - 1].first) + abs(y - arr[i - 1].second));
    debug(prefix[i]);
    arr[i] = {x, y};
  }
  arr[n + 1] = arr[n];
  int ans = dijkstra({0, 0, c, d});
  cout << ans << endl;
  return 0;
}

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

vector<vector<pii> > adjList;
vector<int> a;
vector<vector<int> > dist;
int n, k;

struct node {
  int dist;
  int k;
  int now;
  bool operator<(const node &other) const {
    if (dist != other.dist)
      return dist > other.dist;
    if (k != other.k)
      return k < other.k;
    return now > other.now;
  }
};

int dijsktra() {
  deque<node> dq;
  for (int i = 0; i < n; i++) {
    dq.push_front({0, 1, i});  
    dist[i][1] = 0;
  }
  while (!dq.empty()) {
    node cur = dq.front();
    dq.pop_front();
    if (cur.k == k)
      return cur.dist + 1;
    for (auto it : adjList[cur.now]) {
      if (dist[it.first][cur.k + 1] > cur.dist + it.second) {
        dist[it.first][cur.k + 1] = cur.dist + it.second;
        node new_node = {cur.dist + it.second, cur.k + 1, it.first};
        if (it.second == 1)
          dq.push_back(new_node);
        else dq.push_front(new_node);
      }
    }
  }
  return -1;
}

int main() {
  NeedForSpeed;
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cout << "Case #" << tc << ": ";
    cin >> n >> k;
    adjList.assign(n, vector<pii>());
    dist.assign(n, vector<int>(k + 5, INF));
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < i; j++) {
        if (a[i] > a[j]) {
          adjList[j].pb({i, 0});
        } else if (a[i] < a[j]) {
          adjList[i].pb({j, 1}); 
        }
      }
    }
    cout << dijsktra() << endl;
  }
  return 0;
}

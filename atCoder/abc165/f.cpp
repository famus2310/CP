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

//struct node {
  //int type; //0 change, 1 push
  //int idx = 0, val = 0; //in case of change
//};

vector<int> v;
//node arr[2 * N];
vector<int> adjList[2 * N];
ll ans[2 * N];
int val[2 * N];

void solve(int cur, int par = -1) {
  int lb = lower_bound(all(v), val[cur]) - v.begin();
  if (lb == v.size()) {
    v.pb(val[cur]);
    ans[cur] = v.size();
    for (auto it : adjList[cur]) {
      if (it == par)
        continue;
      solve(it, cur);
    }
    v.pop_back();
  } else {
    int tmp = v[lb];
    v[lb] = val[cur];
    ans[cur] = v.size();
    for (auto it : adjList[cur]) {
      if (it == par)
        continue;
      solve(it, cur);
    }
    v[lb] = tmp;
  }
}
    
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) 
    cin >> val[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  solve(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }  
  return 0;
}

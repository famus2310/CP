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

vector<int> adjList[N];
int primeCnt[N];
bool notPrime[N];
int val[N];

void sieve() {
  SET(notPrime, 0);
  notPrime[0] = notPrime[1] = 1;
  for (ll i = 2; i < N; i++) {
    if (!notPrime[i]) {
      for (ll j = i * i; j < N; j += i)
        notPrime[j] = 1;
    }
  }
}

void dfs(int cur, int par = -1) {
  primeCnt[cur] = !notPrime[val[cur]];
  for (auto it : adjList[cur]) {
    if (it == par)
      continue;
    dfs(it, cur);
    primeCnt[cur] += primeCnt[it];
  }
}

int main() {
  sieve();
  SET(primeCnt, 0);
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> node1;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    node1.pb(a);
  }

  vector<int> node2;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    node2.pb(a);
  }

  for (int i = 0; i < m; i++) {
    adjList[node1[i]].pb(node2[i]); 
    adjList[node2[i]].pb(node1[i]); 
  }
  
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> val[i];
  dfs(1);
  int q;
  cin >> q;
  while (q--) {
    int a;
    cin >> a;
    cout << primeCnt[a] << endl;
  }
  return 0;
}

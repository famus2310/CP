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
const ll MOD = 1ll << 32;
const int INF = 1e9 + 5;
const ll INF64 = 9e18;

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

ll addmod(ll a, ll b) {
  a %= MOD;
  b %= MOD;
  return (a + b) % MOD;
}

ll mulmod(ll a, ll b) {
  a %= MOD;
  b %= MOD;
  return (a * b) % MOD;
}


void mulmod(ll A[105][105], ll B[105][105], const ll n) {
  ll C[105][105];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = INF64;
      for (int k = 0; k < n; k++)
        if (A[i][k] != INF64 && B[k][j] != INF64)
          C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      A[i][j] = C[i][j];
}

ll adjMatrix[105][105];

ll powmod(ll b, ll n) {
  ll ret[105][105];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ret[i][j] = i == j;

  while (b) {
    if (b & 1)
      mulmod(ret, adjMatrix, n);
    b = b / 2;
    mulmod(adjMatrix, adjMatrix, n);
  }
  ll res = INF64;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      res = min(res, ret[i][j]);
  return res;
}

void solve(ll n, ll k) {
  ll ret = powmod(k, n);
  if (ret == INF64)
    cout << "IMPOSSIBLE" << endl;
  else cout << ret << endl;
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      adjMatrix[i][j] = INF64;
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    adjMatrix[u][v] = w;
  }
  solve(n, k); 
  return 0;
}

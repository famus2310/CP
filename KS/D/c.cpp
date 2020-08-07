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
const int N = 5e5 + 5;

ll arr[N];
vector<ll> adjList[N];
ll val[N][2];
ll freq[N][2];
ll ans;

void dfs(ll now, ll a, ll b, ll arrid) {
  arr[arrid] = now;
  for (auto it : adjList[now]) {
    dfs(it, a, b, arrid + 1);
  }
  freq[arr[arrid]][0]++;
  freq[arr[arrid]][1]++;
  if (arrid - a < 0) {
    ans += val[now][0] + freq[now][0];
  }
  else {
    val[arr[arrid - a]][0] += val[now][0] + freq[now][0];
    freq[arr[arrid - a]][0] += freq[now][0];
  }
  if (arrid - b < 0)
    ans += val[now][1] + freq[now][1];
  else {
    val[arr[arrid - b]][1] += val[now][1] + freq[now][1];
    freq[arr[arrid - b]][1] += freq[now][1];
  }
}

int main() {
  ll t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    ans = 0;
    SET(val, 0);
    SET(freq, 0);
    SET(arr, 0);
    for (int i = 0; i < N; i++)
      adjList[i].clear();
    ll n, x, y;
    cin >> n >> x >> y;
    for (int i = 2; i <= n; i++) {
      ll a;
      cin >> a;
      adjList[a].pb(i); 
    }
    dfs(1, x, y, 0);
    ans *= n;
    for (int i = 1; i <= n; i++) {
      ans -= (freq[i][0] * freq[i][1]);
    }
    double dom = n * n;
    SET(arr, 0);
    double ret = (double)(ans) / dom;
    cout << "Case #" << tc << ": " << setprecision(6) << fixed << ret << endl;
  }
  return 0;
}

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

ll mask[N];
ll contribution[N];
bool stocked[N];
vector<ll> fact[N];
vector<ll> prime[N];
bool notPrime[N];
ll sword[N];

void sieve() {
  for (ll i = 2; i < N; i++) {
    if (!notPrime[i]) {
      prime[i].pb(i);
      for (ll j =  2 * i; j < N; j += i) {
        notPrime[j] = 1;
        prime[j].pb(i);
      }
    }
    for (ll j = i; j < N; j += i)
      fact[j].pb(i);
  }
}

void add(ll x, ll val) {
  for (auto it : fact[x]){ 
    contribution[it] += val;
  }
}

ll pie(ll now, ll par, ll prod, ll val) {
  ll ans = 0ll;
  if (par > 0) {
    if (par & 1)
      ans += contribution[prod];
    else ans -= contribution[prod];
  }
  for (ll i = now; i < prime[val].size(); i++) {
    ans += pie(i + 1, par + 1, prod * prime[val][i], val); 
  }
  return ans;
}

ll solve(ll x) {
  ll ret = pie(0, 0, 1ll, x);
  return ret;
} 

int main() {
  SET(stocked, 0);
  sieve();
  ll n, t;
  cin >> n >> t;
  for (int i = 1; i <= n; i++)
    cin >> sword[i];
  ll cnt = 0;
  ll cur = 0;
  for (int i = 1; i <= t; i++) {
    int a;
    cin >> a;
    if (stocked[a]) {
      add(sword[a], -1);
      stocked[a] = 0;
      cnt--;
      cur -= cnt - solve(sword[a]);
    } else {
      cur += cnt - solve(sword[a]);
      cnt++;
      add(sword[a], 1);
      stocked[a] = 1;
    }
    cout << cur << endl;
  }
  return 0;
}

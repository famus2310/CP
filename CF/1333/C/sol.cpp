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

ll suffix[2 * N];
vector<ll> arr;
map<ll, ll> mp;

int main() {
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    arr.pb(x);
  }
  suffix[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    suffix[i] = suffix[i + 1] + arr[i];
  }
  ll bad = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (arr[i] != 0)
        bad++;
      mp[suffix[i]] = i;
    } else {
      ll sr = suffix[i] - arr[i]; 
      if (mp.find(sr) != mp.end())
        bad += i - mp[sr];
      else bad += i + 1;
      if (arr[i] == 0)
        bad--;
      mp[suffix[i]] = i;
    }
    //for (auto it : mp)
      //cout << it.first << ":" << it.second << endl;
  }
  //debug(bad);
  ll ans = bad;
  cout << ans << endl;
  return 0;
}

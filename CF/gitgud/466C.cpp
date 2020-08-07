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

vector<ll> v;
vector<ll> prefix;
vector<ll> suffix;

int main() {
  int n;
  cin >> n;
  v.resize(n);
  prefix.resize(n);
  suffix.resize(n);
  for (auto &it : v)
    cin >> it;
  ll sum = accumulate(all(v), 0ll);
  if (sum % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll target = sum / 3;
  for (int i = 0; i < n; i++) {
    if (i == 0)
      prefix[i] = v[i];
    else prefix[i] = prefix[i - 1] + v[i];
  }
  ll now = 0ll;
  for (int i = n - 1; i >= 0; i--) {
    now += v[i];
    if (i == n - 1)
      suffix[i] = now == target;
    else suffix[i] = suffix[i + 1] + (now == target);
  }
  ll ans = 0ll;
  for (int i = 0; i + 2 < n; i++) {
    if (prefix[i] == target) {
      ans += suffix[i + 2];
    }
  } 
  cout << ans << endl;
  return 0;
}

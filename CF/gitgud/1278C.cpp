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

vector<int> jam;
vector<vector<ll> > leftmost; //sign

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int sum1 = 0;
    int sum2 = 0;
    cin >> n;
    jam.resize(2 * n); 
    leftmost.assign(2 * (n + 1), vector<ll>(2, -1));
    for (auto &it : jam) {
      cin >> it;
      if (it == 1)
        sum1++;
      else sum2++;
    }
    leftmost[0][0] = leftmost[0][1] = 0;
    int cur = 0;
    for (int i = n; i < 2 * n; i++) {
      if (jam[i] == 2)
        cur--;
      else cur++;
      if (cur > 0 && leftmost[cur][0] == -1) {
        leftmost[cur][0] = i - n + 1;
      }
      if (cur < 0 && leftmost[-cur][1] == -1) {
        leftmost[-cur][1] = i - n + 1;
      }
    }
    ll ans = INF64;
    if (sum1 == sum2)
      ans = 0;
    else if (sum1 - sum2 > 0 && leftmost[sum1 - sum2][0] != -1)
      ans = leftmost[sum1 - sum2][0];
    else if (sum1 - sum2 < 0 && leftmost[sum2 - sum1][1] != -1)
      ans = leftmost[sum2 - sum1][1];
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (jam[i] == 2)
        cur--;
      else cur++;
      ll s = sum1 - sum2 - cur;
      if (s == 0)
        ans = min(ans, (ll)n - i);
      if (s > 0 && leftmost[s][0] != -1)
        ans = min(ans, n - i + leftmost[s][0]);
      if (s < 0 && leftmost[-s][1] != -1)
        ans = min(ans, n - i + leftmost[-s][1]);
    }
    cout << ans << endl;
  }
  return 0;
}

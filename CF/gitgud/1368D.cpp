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

vector<int> v;
vector<int> cnt;

int main() {
  int n;
  cin >> n;
  v.resize(n);
  cnt.assign(25, 0);
  for (auto &it : v)
    cin >> it;
  for (int i = 0; i <= 20; i++) {
    int now = -1;
    for (int j = 0; j < n; j++) {
      if ((1 << i) & v[j]) {
        cnt[i]++;
      }
    }
  }
  v.assign(n, 0);
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      v[j] += (1 << i);
    }
  }
  ll sum = 0ll;
  for (int i = 0; i < n; i++) {
    sum += 1ll * v[i] * v[i];
  }
  cout << sum << endl;
  return 0;
}

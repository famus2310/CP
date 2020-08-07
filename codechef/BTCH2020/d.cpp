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

int cnt[1000005];
int arr[1000005];

int main() {
  int t;
  cin >> t;
  while (t--) {
    SET(cnt, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[a]++;
    }
    int now = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        arr[now++] = i;
      }
    }
    int lo = 2, hi = n - 3;
    int cards = n;
    while (lo < hi) {
      if (cnt[arr[lo]] < 2)
        lo++;
      else if (cnt[arr[hi]] < 2)
        hi++;
      else {
        cards -= 2;
        cnt[arr[lo]]--;
        cnt[cnt[hi]]--;
      }
    }
  }
  return 0;
}

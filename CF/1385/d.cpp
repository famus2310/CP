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

int dp[1 << 20][20]; //starting index, split, c-good
char s[1 << 20];
int n;

int solve(int start, int split) {
  int len = n / (1 << split);
  if (len == 0) {
    return split - 1 != s[start] - 'a';
  }
  int ret = dp[start][split];
  if (ret != -1)
    return ret;
  int left_change = 0, right_change = 0;
  for (int i = start; i < start + len; i++) 
    if (s[i] - 'a' != split - 1)
      left_change++;
  for (int i = start + len; i < start + 2 * len; i++) {
    if (s[i] - 'a' != split - 1)
      right_change++;
  }
  dp[start][split] = min(left_change + solve(start + len, split + 1)
        , right_change + solve(start, split + 1));
  return dp[start][split];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    SET(dp, -1);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      char c;
      scanf(" %c", &c);
      s[i] = c;
    }
    printf("%d\n", solve(0, 1));
  }
  return 0;
}

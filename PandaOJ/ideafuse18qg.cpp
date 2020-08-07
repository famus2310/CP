#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int n,k,c;
double dp[1005][20];

int main() {
  scanf("%d%d%d", &n,&k,&c);
  for (int i=0; i<=n; i++) {
    for (int j=1; j<=c; j++) {
      dp[i][j] = 0;
      if (i == 0 && j == c) dp[i][j] = 1;
      if (i-k-1 >= 0) dp[i][j] += dp[i-k-1][1+(j+c-2)%c];
      if (i-k   >= 0) dp[i][j] += dp[i-k  ][1+(j+c-2)%c];
      if (k > 1 && i-k+1 >= 0) dp[i][j] += dp[i-k+1][1+(j+c-2)%c];
    }
  }
  if (dp[n][c] < 0) return 1;
  int e = 0;
  double ans = dp[n][c];
  while (ans >= 10) {
    e++;
    ans /= 10;
  }
  printf("%.3lf x 10^%d\n", ans, e);
}
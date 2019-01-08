#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL memo[405][405];
LL sum[405][405];
LL A[405];

LL stoneGame(LL n) {

      for (LL i = 0; i < n; i++) 
      	memo[i][i] = 0;

      LL left = 0;
      LL right = n - 1;

      for (LL i = 0; i < n; i++) sum[i][i] = A[i];
      for (LL i = 0; i < n; i++) {
          for (LL j = i + 1; j < n; j++) {
              sum[i][j] = sum[i][j-1] + A[j];
          }
      }
      for (LL length = 1; length <= right - left; length++) {
          for (LL start = 0; start < n; start++) {
              LL end = start + length;
              if (end >= n) continue;
              memo[start][end] = INF64;
              for (LL k = start; k < end; k++) {
                  memo[start][end] = min(
                      memo[start][end], 
                      memo[start][k] + memo[k + 1][end] + sum[start][end]);
              }
          }
      }

      return memo[0][n - 1];
  }

int main() {
	LL n;
	scanf("%lld", &n);
	for (LL i = 0; i < n; i++)
		scanf("%lld", A + i);
	printf("%lld\n", stoneGame(n));
	return 0;
}
		
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

LL a[1005];
LL dp[1005][1005];
LL opt[1005][1005];

int main() {
	LL n, k;
	while (scanf("%lld", &n) && n) {
		scanf("%lld", &k);
		for (int i = 1; i <= k; i++)
			scanf("%d", a + i);
		a[0] = 0;
		a[k + 1] = n;
		for (int i = 0; i < k + 2; i++) {
			dp[i][i + 1] = 0;
			opt[i][i + 1] = i;
		}
		for (LL i = 2; i < k + 2; i++) {
			for (LL L = 0; L + i < k + 2; L++) {
				LL R = L + i;
				dp[L][R] = INF;
				for (LL j = max(L + 1, opt[L][R - 1]); j <= min(R - 1, opt[L + 1][R]); j++) {
					LL now = dp[L][j] + dp[j][R] + a[R] - a[L];
					if (dp[L][R] >= now) {
						dp[L][R] = now;
						opt[L][R] = j;
					}
				}
				// cout << "DP[" << L << "][" << R << "] : " << dp[L][R] << endl; 
			}
		}
		printf("The minimum cutting is %lld\n.", dp[0][k + 1]);
 	}
 	return 0;
}
		
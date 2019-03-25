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

LL dp[105][2];

int main() {
	LL n, k, d;
	scanf("%lld %lld %lld", &n, &k, &d);
	SET(dp, 0);
	dp[0][0] = 1;
	for (LL i = 1; i <= n; i++) {
		for (LL j = 1; j <= min(k, i); j++) {
			if (j >= d)
				dp[i][1] = (dp[i][1] + dp[i - j][0] + dp[i - j][1]) % MOD;
			else {
				dp[i][1] = (dp[i][1] + dp[i - j][1]) % MOD;
				dp[i][0] = (dp[i][0] + dp[i - j][0]) % MOD;
			}
		}
	}
	printf("%lld\n", dp[n][1] % MOD);
	return 0;
}

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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e6 + 5;

LL dp[N][2];

int main() {
	LL t;
	scanf("%lld", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL n, m;
		scanf("%lld %lld", &m, &n);
		SET(dp, 0);
		dp[0][0] = 1LL;
		for (LL i = 1; i <= n; i++) {
			int fly = i & 1;
			LL mntake = i * (i + 1) / 2;
			for (LL j = 0; j <= min(mntake - 1, m); j++)
				dp[j][fly] = 0;
			if (mntake <= m)
				dp[mntake][fly] = 1;
			for (LL j = mntake + 1; j <= m; j++) {
				dp[j][fly] = (dp[j - i][fly] + dp[j - i][fly ^ 1]) % MOD;
				// cout << dp[j][fly] << endl;
			}
			// cout << endl;
		}
		printf("Case %d: %lld\n", tc, dp[m][n & 1]);
	}
	return 0;
}
			
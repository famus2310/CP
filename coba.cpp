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

LL dp[3][2 * N];
LL cnt[3];

int main() {
	LL n, l, r;
	cin >> n >> l >> r;
	LL dist = r - l + 1;
	dp[0][1] = dp[1][1] = dp[2][1] = dist / 3;
	if (dist % 3 == 1)
		dp[l % 3][1]++;
	else if (dist % 3 == 2) {
		dp[l % 3][1]++;
		dp[(l + 1) % 3][1]++;
	}
	cnt[0] = dp[0][1];
	cnt[1] = dp[1][1];
	cnt[2] = dp[2][1];
	// cout << dp[1][1] << dp[2][1] << dp[0][1] << endl;
	for (int i = 2; i <= n; i++) {
		dp[0][i] = ((dp[0][i - 1] * cnt[0]) % MOD + (dp[1][i - 1] * cnt[2]) % MOD + (dp[2][i - 1] * cnt[1]) % MOD) % MOD;
		dp[1][i] = ((dp[2][i - 1] * cnt[2]) % MOD + (dp[1][i - 1] * cnt[0]) % MOD + (dp[0][i - 1] * cnt[1]) % MOD) % MOD;
		dp[2][i] = ((dp[1][i - 1] * cnt[1]) % MOD + (dp[0][i - 1] * cnt[2]) % MOD + (dp[2][i - 1] * cnt[0]) % MOD) % MOD;
		// cout << dp[1][i] << dp[2][i] << dp[0][i] << endl;
	}
	printf("%lld\n", dp[0][n]);
	return 0;
}
		
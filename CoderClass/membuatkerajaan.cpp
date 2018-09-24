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

LL grid[105][105];
LL r, c;
LL dp[105];

LL kadane() {
	LL ret = -INF;
	LL sum = 0;
	bool neg = 1;
	for (int i = 0; i < r; i++) {
		sum += dp[i];
		if (sum < 0) {
			sum = 0;
		} else {
			ret = max(ret, sum);
			neg = 0;
		}
	}
	if (!neg) return ret;
	for (int i = 0; i < r; i++) {
		ret = max(ret, dp[i]);
	}
	return ret;
}

LL solve() {
	LL ret = -INF;
	for (int i = 0; i < c; i++) {
		memset(dp, 0, sizeof(dp));
		for (int j = i; j < c; j++) {
			for (int k = 0; k < r; k++) {
				dp[k] += grid[k][j]; 
			}
			LL cur = kadane();
			ret = max(cur, ret);
		}
	}
	return ret;
}

int main() {
	scanf("%lld %lld", &r, &c);
	memset(grid, 0, sizeof(grid));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%lld", &grid[i][j]);
		}
	}
	LL ans = solve();
	printf("%lld\n", ans);
	return 0;
}
		
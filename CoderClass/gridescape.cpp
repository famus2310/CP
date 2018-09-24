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

LL grid[1005][1005];
LL dp[1005][1005];
LL r, c, n;

int main() {
	memset(grid, 0, sizeof(grid));
	scanf("%lld %lld %lld", &r, &c, &n);
	for (int i = 0; i < n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		grid[a - 1][b - 1] = -1;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0 && j == 0) dp[i][j] = 1;
			else if (grid[i][j] == -1) dp[i][j] = 0;
			else if (i == 0) {
				dp[i][j] = dp[i][j - 1];
			} else if (j == 0) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
			}
		}
	}
	printf("%lld\n", dp[r - 1][c - 1] % MOD);
	return 0;
}
		
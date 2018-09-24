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

int dp[25][25];
int grid[25][25];
int n;

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

void init() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			grid[i][j] = 0; dp[i][j] = 0;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		// memset(dp, 0, sizeof(dp));
		// memset(grid, 0, sizeof(grid));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &grid[i][j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i < 2 && j < 2) dp[i][j] = grid[i][j];
				else {
					int tmp1 = 0 + (isBound(i - 2, j) ? dp[i - 2][j] : 0) + (isBound(i, j - 2) ? dp[i][j - 2] : 0) -
					(isBound(i - 2, j - 2) ? dp[i - 2][j - 2] : 0) + grid[i][j];
					int tmp2 = 0 + (isBound(i - 2, j - 1) ? dp[i - 2][j - 1] : 0) + (isBound(i, j - 2) ? dp[i][j - 2] : 0) -
					(isBound(i - 2, j - 2) ? dp[i - 2][j - 2] : 0) + grid[i][j];
					int tmp3 = 0 + (isBound(i - 2, j) ? dp[i - 2][j] : 0) + (isBound(i - 1, j - 2) ? dp[i - 1][j - 2] : 0) -
					(isBound(i - 2, j - 2) ? dp[i - 2][j - 2] : 0) + grid[i][j];
					dp[i][j] = max(tmp1, max(tmp2, tmp3));
				}
				ans = max(dp[i][j], ans);
				// cout << dp[i][j] << " ";
			}
			// cout << endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}
		
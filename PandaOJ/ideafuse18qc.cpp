#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e7;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

char grid[105][105];
int dp[105][2][1005];
int n, m, c;

int solve(int row, int pos, int left) {
	if (row == -1) return left == 0 ? -1 : INF;
	// if (left <= 0) return row;
	left = max(left, 0);
	if (dp[row][pos][left] != -1) return dp[row][pos][left];
	dp[row][pos][left] = solve(row - 1, pos, left) + 1;
	int move = 0;
	int candy = left;
	if (pos) {
		for (int i = 1; i <= m; i++) {
			move++;
			candy -= grid[row][i] - '0';
			dp[row][pos][left] = min(dp[row][pos][left], solve(row - 1, 1, candy) + 2 * move + 1);
			dp[row][pos][left] = min(dp[row][pos][left], solve(row - 1, 0, candy) + m + 2);
		}
	} else {
		for (int i = m; i > 0; i--) {
			move++;
			candy -= grid[row][i] - '0';
			dp[row][pos][left] = min(dp[row][pos][left], solve(row - 1, 0, candy) + 2 * move + 1);
			dp[row][pos][left] = min(dp[row][pos][left], solve(row - 1, 1, candy) + m + 2);	
		}
	}
	return dp[row][pos][left];
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m + 1; j++) {
			scanf(" %c", &grid[i][j]);
		}
	}
	printf("%d\n", solve(n - 1, 1, c));	
	return 0;
}
		
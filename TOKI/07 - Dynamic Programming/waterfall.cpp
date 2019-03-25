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

bool grid[505][505]; //1 = stone
LL dp[505][505];

void deb(int x,  int y) {
	for (int i = 0; i <= y + 1; i++)
		cout << dp[x][i] << " ";
	cout << endl;
}

int main() {
	SET(dp, 0);
	int v, h, n;
	scanf("%d %d %d", &v, &h, &n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int j = a; j <= c; j++) {
			for (int k = b; k <= d; k++) {
				grid[j][k] = 1;
			}
		}
	}
	for (int i = v; i >= 0; i--) {
		//fill from bottom
		for (int j = 1; j <= h; j++) {
			if (grid[i][j])
				continue;
			dp[i][j] = dp[i + 1][j];
		}
		// deb(i, h);
		//fill from left
		for (int j = 1; j <= h; j++) {
			if (!grid[i + 1][j] || grid[i][j])
				continue;
			if (!grid[i + 1][j - 1])
				dp[i][j] = dp[i][j] + dp[i][j - 1];
			else dp[i][j] = dp[i][j - 1];
		}
		// deb(i, h);
		//fill from right
		for (int j = h; j >= 0; j--) {
			if (!grid[i + 1][j] || grid[i][j])
				continue;
			if (!grid[i + 1][j + 1])
				dp[i][j] = dp[i][j] + dp[i][j + 1];
			else dp[i][j] = dp[i][j + 1];
		}
		// deb(i, h);
		//fill splash
		for (int j = 1; j <= h; j++) {
			if (grid[i][j])
				continue;
			if (grid[i + 1][j] || grid[i][j])
				dp[i][j] = dp[i][j] + 1;
		}
		// deb(i, h);
		// cout << endl;
	}	
	LL mx = 0LL;
	// for (int i = 0; i <= v + 1; i++) {
	// 	for (int j = 0; j <= h + 1; j++)
	// 		cout << grid[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << endl;
	// for (int i = 0; i <= v + 1; i++) {
	// 	for (int j = 0; j <= h + 1; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	for (int i = 1; i <= h; i++) {
		mx = max(mx, dp[0][i]);
	}
	printf("%lld\n", mx);
	return 0;
}
		
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

const int N = 1e5 + 5;

char grid[105][105];
LL dp[105][1005][2]; //floor, candy, isleft
LL n, m, c;


int main() {
	fastio;
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 1005; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = INF64;
	// dp[0][0][0] = 0;
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m + 1; j++)
			cin >> grid[i][j];
	}
	dp[n - 1][c][0] = 0;
	for (int candy = 1004; candy >= 0; candy--) {
		int now = 0;
		for (int i = 1; i <= m; i++) {
			now = now + (grid[n - 1][i] - '0');
			if (now + candy <= c) {
				dp[n - 1][candy][0] = min(dp[n - 1][candy][0], dp[n - 1][candy + now][0] + 2 * i);
				dp[n - 1][candy][1] = min(dp[n - 1][candy][1], dp[n - 1][candy + now][0] + m + 1);
			}
		}
		if (candy <= c)
			cout << dp[n - 1][candy][0] << " " << dp[n - 1][candy][1] << endl;
	}

	for (int i = n - 2; i >= 0; i--) {
		cout << endl;
		for (int candy = 1004; candy >= 0; candy--) {
			dp[i][candy][0] = dp[i + 1][candy][0] + 1;
			dp[i][candy][1] = dp[i + 1][candy][1] + 1;
			int now = 0;
			for (int j = 1; j <= m; j++) {
				now = now + grid[i][j] - '0';
				if (now <= candy) {
					dp[i][candy][0] = min(dp[i][candy][0], dp[i + 1][candy - now][0] + 2 * j + 1);
					dp[i][candy][0] = min(dp[i][candy][0], dp[i + 1][candy - now][1] + m + 2);
				}
			}
			now = 0;
			int move = 0;
			for (int j = m; j > 0; j--) {
				move++;
				now = now + grid[i][j] - '0';
				if (now <= candy) {
					dp[i][candy][1] = min(dp[i][candy][1], dp[i + 1][candy - now][1] + 2 * move + 1);
					dp[i][candy][1] = min(dp[i][candy][1], dp[i + 1][candy - now][0] + m + 2);
				}
			}
			if (candy <= c)
				cout << dp[i][candy][0] << " " << dp[i][candy][1] << endl;
		}
	}
	cout << min(dp[0][c][0], dp[0][c][1]) << endl;
	return 0;
}
		
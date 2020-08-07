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
const int ROW = 205;
const int COL = 205;

int t;
int n;
LL dp[ROW][COL];

int main() {
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		SET(dp, 0);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				LL a;
				scanf("%lld", &a);
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a;
				// cout << dp[i][j] << " ";
			}
			// cout << endl;
		}
		for (int i = 1; i <= n - 1; i++) {
			for (int j = 1; j <= n - i; j++) {
				LL a;
				scanf("%lld", &a);
				dp[n + i][j] = max(dp[n + i - 1][j], dp[n + i - 1][j + 1]) + a;
				// cout << n + i << " " << j << " : " << dp[n + i][j] << " ";
			}
			// cout << endl;
		}
		printf("Case %d: %lld", tc, dp[2 * n - 1][1]);
	}
	return 0;
}
		
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

LL dp[105][505];
LL cost[105];
LL val[105];

int main() {
	LL b, n;
	while (scanf("%lld %lld", &b, &n), b && n) {
		for (int i = 1; i <= n; i++) 
			scanf("%lld %lld", cost + i, val + i);

		SET(dp, 0);
		for (int k = 1; k <= b; k++) {
			for (int i = 1; i <= n; i++) {	
				dp[i][k] = dp[i - 1][k];
				if (k >= cost[i])
					dp[i][k] = max(dp[i][k], dp[i - 1][k - cost[i]] + val[i]);
			}
		}
		while (b > 1 && dp[n][b] == dp[n][b - 1])
			b--;
		printf("%lld %lld\n", b, dp[n][b]);
	}
	return 0;
}
		
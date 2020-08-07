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

LL t[N][2];
LL a[N][2];
LL dp[N][2];

int main() {
	LL n;
	while (scanf("%lld", &n) == 1) {
		scanf("%lld %lld", &t[0][0], &t[0][1]);
		for (int i = 1; i <= n; i++) 
			scanf("%lld", &a[i][0]);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i][1]);

		for (int i = 1; i <= n; i++) 
			scanf("%lld %lld", &t[i][0], &t[i][1]);
		// scanf("%lld %lld", &t[n][0], &t[n][0]);
		dp[1][0] = t[0][0] + a[1][0];
		dp[1][1] = t[0][1] + a[1][1];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + t[i - 1][1]) + a[i][0];
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + t[i - 1][0]) + a[i][1];
			// cout << dp[i][0] << " " << dp[i][1] << endl;
		}
		dp[n + 1][0] = dp[n][0] + t[n][0];
		dp[n + 1][1] = dp[n][1] + t[n][1];
		printf("%lld\n", min(dp[n + 1][0], dp[n + 1][1]));
	}
	return 0;
}
		
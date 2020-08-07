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

LL dp[8005];

int main() {
	LL n;
	scanf("%lld", &n);
	dp[0] = 0;
	dp[1] = 1;
	for (LL i = 2; i < 8005; i++) {
		dp[i] = 10 * dp[i - 1] + 1;
		for (LL j = 2; j <= 9; j++) {
			if (j * j * j > i)
				break;
			dp[i] = min(10 * dp[i - (j * j * j)] + j, dp[i]);
		}
		// if (i <= 10)
			// cout << dp[i] << endl;
 	}
	printf("%lld\n", dp[n]);
	return 0;
}
		
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

LL n, k;
LL dp[105][N];
LL a[105];

int main() {
	fastio;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= k; i++)
		dp[0][i] = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - 1 >= 0)
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
			if (j - a[i] - 1 >= 0)
				dp[i][j] = (dp[i][j] - dp[i - 1][j - a[i] - 1] + MOD) % MOD; 
			// cout << dp[i][j] << " "	;
		}
		// cout << endl;
	}
	cout << dp[n][k] << endl;	
	return 0;
}
		
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

LL dp[10005][105];
LL prefix[10005][105];

void preprocess() {
	SET(dp, 0);
	SET(prefix, 0);
	for (int i = 1; i < 10005; i++) {
		for (int j = 1; j < 105; j++) {
			if (i == 1 || j == 1)
				dp[i][j] = 1;
			else if (i <= j)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			else {
				dp[i][j] = prefix[i - 1][j];
			}
			prefix[i][j] = (prefix[i - 1][j] + dp[i][j]) % MOD;
			if (i > j)
				prefix[i][j] = (prefix[i][j] - dp[i - j][j] + MOD) % MOD;
			// cout << prefix[i][j] << " ";
 		}
 		// cout << endl;
	}
}

int main() {
	preprocess();
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%lld\n", dp[n][k] % MOD);
	}
	return 0;
}
		
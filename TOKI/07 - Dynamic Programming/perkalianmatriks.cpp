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
const int MOD = 26101991;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL catalan[105];
LL dp[105][105];
pair<LL, LL> mat[105];
LL dpcnt[105][105];

LL cost(LL x, LL y, LL z) {
	return mat[x].first * mat[y].second * mat[z].second;
}

void precomp() {
	catalan[1] = catalan[2] = 1;
	for (LL i = 3; i < 105; i++) {
		catalan[i] = 0LL;
	 	for (LL j = 1; j < i; j++)
			catalan[i] = (catalan[i] + (catalan[j] * catalan[i - j]) % MOD) % MOD;
	}
	for (LL i = 0; i < 105; i++)
			dpcnt[i][1] = 1;
}

int main() {
	precomp();
	LL n;
	scanf("%lld", &n);
	for (int i = 0; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		mat[i].first = a;
		if (i != 0)
			mat[i - 1].second = a;
	}
	SET(dp, 0);
	for (LL i = 2; i <= n; i++) {
		for (LL j = 0; j <= n - i; j++) {
			dp[j][i] = dp[j][1] + dp[j + 1][i - 1] + cost(j, j, j + i - 1);
			dpcnt[j][i] = (dpcnt[j][1] * dpcnt[j + 1][i - 1]) % MOD;
			for (LL k = 2; k < i; k++) {
				if (dp[j][i] > dp[j][k] + dp[j + k][i - k] + cost(j, j + k - 1, j + i - 1)) {
					dpcnt[j][i] = (dpcnt[j][k] * dpcnt[j + k][i - k]) % MOD;
				} else if (dp[j][i] == dp[j][k] + dp[j + k][i - k] + cost(j, j + k - 1, j + i - 1))
					dpcnt[j][i] = (dpcnt[j][i] + (dpcnt[j][k] * dpcnt[j + k][i - k]) % MOD) % MOD;
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[j + k][i - k] + cost(j, j + k - 1, j + i - 1));
			}
		}
	}
	int q;
	scanf("%d", &q);
	if (q == 1)
		printf("%lld\n", dp[0][n]);
	else if (q == 2)
		printf("%lld\n", dpcnt[0][n]);
	else printf("%lld\n", catalan[n]);
	return 0;
}
		
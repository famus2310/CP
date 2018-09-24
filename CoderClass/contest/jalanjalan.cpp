#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;



LL t, n;
LL D[205];
LL dp[205][N];
LL sum = 0;
list<char> ans;

void knapsack(LL m) {
	for (LL i = 0; i <= n; i++) {
		for (LL j = 0; j <= m; j++) {
			if (j == 0 || i == 0) 
				dp[i][j] = 0;
			else if (j >= D[i - 1]) { //&& j >= sum - D[i - 1])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - D[i - 1]] + D[i - 1]);
			} else 
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%lld\n", dp[n][m] * (sum - dp[n][m]));
	LL tmpm = m, tmpn = n;
	while (tmpn > 0) {
		if (dp[tmpn - 1][tmpm] == dp[tmpn][tmpm]) {
			tmpn--;
			ans.pb('R');
		} else {
			tmpm -= D[tmpn - 1];
			tmpn--;
			ans.pb('D');
		}
	}
	while (!ans.empty()) {
		cout << ans.back();
		ans.pop_back();
	}
	puts("");
}

int main() {
	// auto ti = clock();
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", D + i);
			sum += D[i];
		}
		knapsack(sum / 2);
	}
	// cout << (double)(clock() - ti) / CLOCKS_PER_SEC << endl;
	return 0;
}
		
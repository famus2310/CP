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

LL n, m;
LL val[1005];
LL weight[1005];
LL dp[5005];

LL knapsack() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (weight[j] <= i) {
				dp[i] = max(dp[i], val[j] + dp[i - weight[j]]);
			}
		}
	}
	return dp[m];
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld %lld", weight + i, val + i);
	printf("%lld\n", knapsack());
	return 0;
}
		
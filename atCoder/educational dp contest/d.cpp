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

LL dp[105][N]; //W, N
LL val[N];
LL weight[N];

LL knapsack(LL n, LL w) {
	for (LL i = 0; i <= n; i++) {
		for (LL j = 0; j <= w; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0LL;
			else if (weight[i - 1] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + val[i - 1]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][w];
} 

int main() {
	LL n, w;
	scanf("%lld %lld", &n, &w);
	for (int i = 0; i < n; i++) 
		scanf("%lld %lld", weight + i, val + i);
	printf("%lld\n", knapsack(n, w));
	return 0;
}
		
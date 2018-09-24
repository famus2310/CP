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

LL n, w;
LL val[105], weight[105];
LL dp[10005];

void knapsack() {
	for (int i = 0; i <= w; i++) {
		for (int j = 0; j < n; j++) {
			if (weight[j] <= i) dp[i] = max(dp[i], dp[i - weight[j]] + val[j]);
		}
	}
}

int main() {
	scanf("%lld %lld", &n, &w);
	for (int i = 0; i < n; i++) scanf("%lld %lld", val + i, weight + i);
	knapsack();
	printf("%lld\n", dp[w]);
	return 0;
}
		
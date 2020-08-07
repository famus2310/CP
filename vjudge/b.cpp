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
LL arr[25];
LL dp[50005];

void init() {
	for (int i = 0; i < 50005; i++) dp[i] = INF;
}

int main() {
	init();
	dp[0] = 0;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; i++) scanf("%lld", arr + i);
	for (int i = 0; i < m; i++) {
		for (int j = arr[i]; j <= n; j++) dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
	}
	printf("%lld\n", dp[n]);
	return 0;
}
		
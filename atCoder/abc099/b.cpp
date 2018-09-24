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

LL dp[N];
set<LL> change;

int main() {
	for (LL i = 0; i < N; i++) dp[i] = INF;
	dp[0] = 0;
	change.insert(1);
	LL now = 6;
	while (now < N) {
		change.insert(now);
		now *= 6;
	}
	now = 9;
	while (now < N) {
		change.insert(now);
		now *= 9;
	}
	LL n;
	scanf("%lld", &n);
	for (auto it : change) {
		for (LL j = it; j <= n; j++) {
			dp[j] = min(dp[j - it] + 1, dp[j]);
 		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}
		
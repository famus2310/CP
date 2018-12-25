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

const int N = 1e6 + 5;

LL dp[N];
vector<pair<LL, LL> > add;

LL solve(LL x) {
	LL ret = 0LL;
	for (LL i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			if (dp[i - 1] != 0) {
				ret = (ret + dp[i - 1]) % MOD;
				add.pb({i, dp[i - 1]});
			}
			if (x / i != i && dp[x / i - 1] != 0) {
				ret = (ret + dp[x / i - 1]) % MOD;
				add.pb({x / i, dp[x / i - 1]});	
			}
		}
	}
	for (auto it : add) {
		dp[it.first] = (dp[it.first] + it.second) % MOD;
	}
	add.clear();
	return ret % MOD;
}

int main() {
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	int n;
	LL ans = 0LL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		ans = (ans + solve(a)) % MOD;
		// debug(ans);
	}
	printf("%lld\n", ans);
	return 0;
}
				
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

LL cost[N];
LL cnt[N];
LL dp[1005]; //transition = cost

void solve(LL n) { 
	for (int i = 0; i < 1005; i++)
		dp[i] = MOD;
	dp[0] = 0;
	for (LL i = 0; i < 1005; i++) {
		for (LL j = 0; j < n; j++) {
			if (cnt[j] <= i) 
				dp[i] = min(dp[i], dp[i - cnt[j]] + cost[j]);
			// debug(dp[i]);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, q;
		scanf("%lld %lld", &n, &q);
		for (int i = 0; i < n; i++) {
			LL a, b;
			scanf("%lld %lld", &a, &b);
			cost[i] = b;
			cnt[i] = a;
 		}
 		solve(n);
 		while (q--) {
 			LL a;
 			scanf("%lld", &a);
 			printf("%lld\n", dp[a]);
 		}
	}
	return 0;
}
		
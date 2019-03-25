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

LL dp[10005];
LL val[505], w[505];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(dp, 0);
		LL a, b;
		scanf("%lld %lld", &a, &b);
		LL target = b - a;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld %lld", val + i, w + i);
		for (int i = 1; i <= target; i++) {
			dp[i] = INF;
			for (int j = 1; j <= n; j++) {
				if (w[j] > i)
					continue;
				dp[i] = min(dp[i], dp[i - w[j]] + val[j]);
			}
			// cout << dp[i] << endl;
		}
		if (dp[target] == INF)
			puts("This is impossible.");
		else printf("The minimum amount of money in the piggy-bank is %lld.\n", dp[target]);
	}
	return 0;
}
		
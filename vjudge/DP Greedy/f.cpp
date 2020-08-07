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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 15;

LL dp[N];
LL arr[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(arr, 0);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", arr + i);
		}
		SET(dp, -1);
		dp[0] = 0;
		LL ans = 0LL;
		for (int i = 1; i <= n + 6; i++) {
			if (i > 5 && dp[i - 6] != -1)
				dp[i] = max(dp[i], dp[i - 6] + arr[i - 3] + arr[i - 4] + arr[i - 5]);
			if (i > 3 && dp[i - 4] != -1)
				dp[i] = max(dp[i], dp[i - 4] + arr[i - 2] + arr[i - 3]);
			if (i > 1 && dp[i - 2] != -1)
				dp[i] = max(dp[i], dp[i - 2] + arr[i - 1]);
			// cout << dp[i] << " ";
			ans = max(ans, dp[i]);
		}
		// cout << endl;
		printf("%lld\n", ans);
	}
	return 0;
}
		
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

LL dp[105][105];

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		SET(dp, 0);
		LL n;
		LL mx = 0LL;
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				LL a;
				scanf("%lld", &a);
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a;
				mx = max(mx, dp[i][j]);
			}
		}
		printf("%lld\n", mx);
	}
	return 0;
}
		
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

LL dp[55];

int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0LL;
		if (i & 1)
			continue;
		else {
			LL sum = i - 2;
			for (LL j = 0; j <= sum; j++) {
				dp[i] = dp[i] + dp[j] * dp[sum - j];
			}
		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}
		
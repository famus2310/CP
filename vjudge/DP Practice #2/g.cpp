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

LL n;
LL arr[1005];
LL dp[1005];

LL solve() {
	LL ret = arr[0];
	SET(dp, 0);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j]);
			} 
		}
		dp[i] += arr[i];
		ret = max(dp[i], ret);
	}
	return ret;
}

int main() {
	while (scanf("%lld", &n), n) {
		for (int i = 0; i < n; i++) {
			scanf("%lld", arr + i);
		}
		printf("%lld\n", solve());
	}

	return 0;
}
		
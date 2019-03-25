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

LL dp[2005][2005];
LL arr[2005];

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", arr + i);
	for (int i = 1; i <= n; i++) {
		dp[i][i] = n * arr[i];
	}

	for (int k = 1; k < n; k++) {
		for (int j = 1; j + k <= n; j++) {
			dp[j][j + k] = max((n - k) * arr[j] + dp[j + 1][j + k], (n - k) * arr[j + k] + dp[j][j + k - 1]);
		}
	}

	printf("%lld\n", dp[1][n]);
	return 0;
}
		
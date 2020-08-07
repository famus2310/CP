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

const int N = 2005;
const int ALP = 26;

char arr[N];
LL dp[N][ALP];

int main() {
	SET(dp, 0);
	LL n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %c", arr + i);
		for (int j = 0; j < 26; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		dp[i][arr[i] - 'a']++;
	}

	LL ans = 0LL;
	for (int i = 1; i <= n - 3; i++) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j]) {
				// cout << i << " " << j << endl;
				for (int k = 0; k < ALP; k++) {
					ans += (dp[j - 1][k] - dp[i][k]) * (dp[n][k] - dp[j][k]);
				}
				// debug(ans);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
		
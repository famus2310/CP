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

const int N = 1e5 + 5;

LL dp[3005][3005]; // n,  k;

int main() {
	LL n;
	while (scanf("%lld", &n) == 1) {
		SET(dp, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = INF;
				if (prefix[i] - prefix[i - j] >= dp[i - 1][i - j])
					dp[i][j] = min(dp[i][j], dp[i - 1][i - j] + prefix[i] - prefix[i - j]);
			}
		}
	}
	return 0;
}
		
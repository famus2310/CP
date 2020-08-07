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

LL dp[1005][1005];

int main() {
	int h, w;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			dp[i][j] = 0LL;
			char c;
			cin >> c;
			if (c == '.') {
				if (i == 0 && j == 0)
					dp[i][j] = 1;
				else if (i == 0)
					dp[i][j] = dp[i][j - 1];
				else if (j == 0)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			} else dp[i][j] = 0;

			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	printf("%lld\n", dp[h - 1][w - 1]);
	return 0;
}
		
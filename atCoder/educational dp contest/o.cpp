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

bool grid[25][25];
LL dp[25][(1LL << 22)];

int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];
	}
	SET(dp, 0);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			if (dp[i - 1][j] == 0 || __builtin_popcount(j) != i - 1)
				continue;
			for (int k = 0; k < n; k++) {
				int setted = n - k - 1;
				if (grid[i][k] == 1 && !(j & (1 << setted))) {
					dp[i][j ^ (1 << setted)] = (dp[i][j ^ (1 << setted)] + dp[i - 1][j]) % MOD;
				}
			}
		}
	}
	cout << dp[n][(1 << n) - 1] << endl;
	return 0;
}
		
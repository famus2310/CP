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

int dp[15][1005]; //alt, dist
int wind[15][1005]; //

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n = n / 100;
		for (int i = 9; i >= 0; i--) {
			for (int j = 1; j <= n; j++) {
				cin >> wind[i][j];
			}
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == 0) {
					if (j == 0)
						dp[j][i] = 0;
					else dp[j][i] = INF;
				} else {
					dp[j][i] = dp[j][i - 1]  - wind[j][i] + 30;
					if (j > 0)
						dp[j][i] = min(dp[j][i], dp[j - 1][i - 1] - wind[j][i] + 60);
					if (j < 9)
						dp[j][i] = min(dp[j][i], dp[j + 1][i - 1] - wind[j][i] + 20);
 				}
 				cout << dp[j][i] << " ";
			}
			cout << endl;
		}
		cout << dp[0][n] << endl;
	}
	return 0;
}
/*
2
400
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 9 9 1
1 -9 -9 1
1000
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
9  9  9  9  9  9  9  9  9  9
7  7  7  7  7  7  7  7  7  7
-5 -5 -5 -5 -5 -5 -5 -5 -5 -5
-7 -3 -7 -7 -7 -7 -7 -7 -7 -7
-9 -9 -9 -9 -9 -9 -9 -9 -9 -9
*/
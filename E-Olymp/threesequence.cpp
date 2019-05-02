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

LL a[105], b[105], c[105];
LL dp[105][105][105];
LL n, m, o;

int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	cin >> o;
	for (int i = 0; i < o; i++)
		cin >> c[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= o; k++) {
				if (i == 0 || j == 0 || k == 0)
					dp[i][j][k] = 0;
				else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) 
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}
	cout << dp[n][m][o] << endl;
 	return 0;
}
		
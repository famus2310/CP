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


string hard = " hard";
char s[N];
LL dp[N][5];
LL comp[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++)
		cin >> comp[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 4; j++) {
			if (i == 0)
				dp[i][j] = 0;
			else dp[i][j] = INF;
		}
	}
	dp[0][0] = INF64;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 4; j++) {
			if (s[i] == hard[j]) {
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + comp[i]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
			// cout << dp[i][j] <<" ";
		}
		// cout << endl;
	}

	LL ans = INF64;
	for (int i = 0; i <= 4; i++)
		ans = min(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}
		
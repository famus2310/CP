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

string a, b;
int dp[105][105];

int solve() {
	int ret = 0;
	memset(dp, 0, sizeof dp);
	for (int i = 0; i <= a.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ret = max(ret, dp[i][j]);
 			} else dp[i][j] = 0;
		}
	}
	return ret;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		int ans = solve();
		if (ans >= k)
			puts("Yes");
		else puts("No");
	}
	return 0;
}
		
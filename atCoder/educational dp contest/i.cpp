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

double dp[3005][3005]; //current, head
double prob[3005];

int main() {
	SET(dp, 0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", prob + i);
	}
	dp[0][0] = 1 - prob[0];
	dp[0][1] = prob[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][0] * (1.0 - prob[i]); 
			} else
				dp[i][j] = dp[i - 1][j] * (1.0 - prob[i]) + dp[i - 1][j - 1] * prob[i]; 
		}
	}
	double ans = 0;
	for (int i = (n + 1) / 2; i <= n; i++) {
		ans += dp[n - 1][i];
	}
	printf("%.9lf\n", ans);
	return 0;
}
		
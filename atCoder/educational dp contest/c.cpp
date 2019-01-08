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

int activity[N][3];
int dp[N][3];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &activity[i][j]);
			if (i == 0)
				dp[i][j] = activity[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++)
			dp[i][j] = activity[i][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
	}
	printf("%d\n", max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])));
	return 0;
}
		
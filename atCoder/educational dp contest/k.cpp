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

int n, k;
int dp[N][2];
int arr[105];

int main() {
	scanf("%d %d", &n, &k);
	dp[0][0] = 1;
	dp[0][1] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	for (int i = 1; i <= k; i++) {
		dp[i][0] = 1;
		dp[i][1] = 0;
		for (int j = 0; j < n; j++) {
 			if (i < arr[j]) {
				dp[i][0] = min(1, dp[i][0]);
				dp[i][1] = max(0, dp[i][1]);
 			}
			else {
				dp[i][0] = min(dp[i][0], dp[i - arr[j]][1]);
				dp[i][1] = max(dp[i][1], dp[i - arr[j]][0]);
			}
		}
		// cout << dp[i][0] << dp[i][1] << endl;
	}
	if (dp[k][0] == 0)
		puts("First");
	else puts("Second"); 
	return 0;
}
		
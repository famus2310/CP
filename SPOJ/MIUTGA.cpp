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
 
int arr[N];
int n;
int dp[N][2][2]; //pos, up, change

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < N; i++)
			dp[i][0][0] = dp[i][1][0] = dp[i][0][1] = dp[i][1][1] = INF;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) 
			scanf("%d", arr + i);
		for (int i = 1; i <= (n + 1) / 2; i++) {
			if (i == 1) {
				dp[i][0][0] = dp[i][1][0] = 0;
				dp[i][0][1] = dp[i][1][1] = 1;
				continue;
			}
			if (n & 1) {
				if (arr[i - 1] < arr[i] && arr[n - i + 1] > arr[n - i + 2]) {
					dp[i][1][0] = min(dp[i][1][0], dp[i - 1][0][0]);
				}
				if (arr[i - 1] > arr[i] && arr[n - i + 1] < arr[n - i + 2]) {
					dp[i][0][0] = min(dp[i][0][0], dp[i - 1][1][0]);
				}
				if (arr[n - i + 2] < arr[i] && arr[n - i + 1] > arr[i - 1]) {
					dp[i][1][0] = min(dp[i][1][0], dp[i - 1][0][1]);
				}
				if (arr[n - i + 2] > arr[i] && arr[n - i + 1] < arr[i - 1]) {
					dp[i][0][0] = min(dp[i][0][0], dp[i - 1][1][1]);
				}
				if (arr[i - 1] < arr[n - i + 1] && arr[i] > arr[n - i + 2]) {
					dp[i][1][1] = min(dp[i][1][1], dp[i - 1][0][0] + 1);
				}
				if (arr[i - 1] > arr[n - i + 1] && arr[i] < arr[n - i + 2]) {
					dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][0] + 1);
				}
				if (arr[n - i + 2] < arr[n - i + 1] && arr[i] > arr[i - 1]) {
					dp[i][1][1] = min(dp[i][1][1], dp[i - 1][0][1] + 1);
				}
				if (arr[n - i + 2] > arr[n - i + 1] && arr[i] < arr[i - 1]) {
					dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][1] + 1);
				}
			} else {
				if (arr[i - 1] > arr[i] && arr[n - i + 1] > arr[n - i + 2] || i != (n + 1) / 2) {
					dp[i][0][0] = min(dp[i][0][0], dp[i - 1][1][0]);
				}
				if (arr[i - 1] < arr[i] && arr[n - i + 1] < arr[n - i + 2] || i != (n + 1) / 2) {
					dp[i][1][0] = min(dp[i][1][0], dp[i - 1][0][0]);
				}
				if (arr[n - i + 2] > arr[i] && arr[n - i + 1] > arr[i - 1] || i != (n + 1) / 2) {
					dp[i][0][0] = min(dp[i][0][0], dp[i - 1][1][1]);
				}
				if (arr[n - i + 2] < arr[i] && arr[n - i + 1] < arr[i - 1] || i != (n + 1) / 2) {
					dp[i][1][0] = min(dp[i][1][0], dp[i - 1][0][1]);
				}
				if (arr[i - 1] > arr[n - i + 1] && arr[i] > arr[n - i + 2] || i != (n + 1) / 2) {
					dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][0] + 1);
				}
				if (arr[i - 1] < arr[n - i + 1] && arr[i] < arr[n - i + 2] || i != (n + 1) / 2) {
					dp[i][1][1] = min(dp[i][1][1], dp[i - 1][0][0] + 1);
				}
				if (arr[n - i + 2] > arr[n - i + 1] && arr[i] > arr[i - 1] || i != (n + 1) / 2) {
					dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][1] + 1);
				}
				if (arr[n - i + 2] < arr[n - i + 1] && arr[i] < arr[i - 1] || i != (n + 1) / 2) {
					dp[i][1][1] = min(dp[i][1][1], dp[i - 1][0][1] + 1);
				}
	
			}
			cout << i << ": " << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << endl;
		}
		int ans = INF;
		int mid = (n + 1) / 2;
		ans = min(ans, dp[mid][0][0]);
		ans = min(ans, dp[mid][0][1]);
		ans = min(ans, dp[mid][1][0]);
		ans = min(ans, dp[mid][1][1]);
		if (n == 1) ans = 0;
		if (n == 2) {
			if (arr[1] < arr[2] || arr[1] > arr[2])
				ans = 0;
			else ans = INF;
		}
		if (ans >= INF)
			puts("-1");
		else printf("%d\n", ans); 
	}
	return 0;
}
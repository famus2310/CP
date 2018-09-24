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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int dp[N];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int ans = 0;
		int n;
		scanf("%d", &n);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			if (i == 0) continue;
			else {
				dp[i] = a;
				for (int j = 4; j > 1; j--) {
					if (i - j >= 0) dp[i] = max(dp[i], a + dp[i - j]);
				}
				ans = max(ans, dp[i]);
			}
		}
		printf("Case %d :%d\n", tc, ans);
	}
	return 0;
}
		
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
int dp[10 * N][25];
int freq[10 * N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(dp, 0);
		SET(freq, 0);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			freq[arr[i]]++;
		}

		
		// for (int mask = 0; mask < (1LL << 20); mask++) {
		// 	dp[mask][0] = freq[mask];
		// 	if (mask & 1)
		// 		dp[mask][0] = dp[mask][0] + freq[mask ^ 1];
		// 	for (int i = 1; i <= 20; i++) {
		// 		dp[mask][i] = dp[mask][i - 1];
		// 		if (mask & (1LL << i))
		// 			dp[mask][i] = dp[mask][i] + dp[mask ^ (1LL << i)][i - 1];
		// 	}
		// }

				for(int mask=0;mask<(1ll<<20);++mask)
		{
			dp[mask][0]=freq[mask];
			if(mask&1)
				dp[mask][0]+=freq[mask^1];
			for(int p=1;p<=20;++p)
			{
				dp[mask][p]=dp[mask][p-1];
				if(mask&(1<<p))
				{
					dp[mask][p]+=dp[mask^(1<<p)][p-1];
				}
			}
		}
		int ans = 0;

		for (int i = 0; i < n; i++) {
			ans = ans + dp[(1LL << 20) - 1 - arr[i]][20];
			debug(i);
		}

		printf("%d\n", ans);
	}
	return 0;
}
		
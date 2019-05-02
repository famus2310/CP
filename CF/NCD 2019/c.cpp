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

LL dp[1005];
LL arr[1005];
LL cntLis[1005];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(dp, 0);
		SET(cntLis, 0);
		LL lis = 0;
		LL cnt = 0;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", arr + i);
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			cntLis[i] = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] < arr[i]) {
					if (dp[j] + 1 < dp[i])
						continue;
					if (dp[i] == dp[j] + 1) {
						cntLis[i] = (cntLis[i] + cntLis[j]) % MOD;
					} else 
						cntLis[i] = cntLis[j];
					dp[i] = dp[j] + 1;
				}
			}
			if (dp[i] > lis) {
				lis = dp[i];
				cnt = cntLis[i];
			} else if (dp[i] == lis) {
				cnt = (cnt + cntLis[i]) % MOD;
			}
			// cout << dp[i] << endl;
		}
		printf("%lld %lld\n", lis, cnt);
	}
	return 0;
}
		
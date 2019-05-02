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

bool dp[10005][10005];
LL arr[10005];
LL ori[10005];
vector<LL> ans;

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", arr + i);
		ori[i] = arr[i];
 		if (arr[i] > n)
			arr[i] = arr[i] % n;
	}
	LL now;
	bool fnd = 0;
	for (int i = 1; i <= n; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= n; j++) {
			// cout << i << " " << j << endl;
			dp[i][j] = 0;
			if (j == arr[i]) {
				dp[i][j] = 1;
				continue;
			}
			if (dp[i - 1][j]) {
				dp[i][j] = 1;
				continue;
			}
			if (j - arr[i] > 0 && dp[i - 1][j - arr[i]]) {
				dp[i][j] = 1;
			}
 		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	now = n;
	LL sum = n;
	if (!dp[n][n]) {
		cout << 0 << endl;
		return 0;
	}
	// cout << now << " " << sum << endl;
	while (1) {
		// debug(now);
		// debug(sum);
		while (now > 1 && dp[now - 1][sum])
			now--;
		ans.pb(now);
		if (arr[now] == sum)
			break;
		sum -= arr[now];
		now--;
	}
	cout << ans.size() << endl;
	for (auto it : ans)
		cout << ori[it] << endl;
	return 0;
}
		
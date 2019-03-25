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

LL dp[5005][5005]; //pos right, x;
LL arr[5005];

int main() {
	SET(dp, -1);
	LL n, k, x;
	scanf("%lld %lld %lld", &n, &k, &x);
	for (int i = 1; i <= n; i++)
		scanf("%lld", arr + i);
	for (int i = 1; i <= k; i++) {
		dp[i][1] = arr[i];
		// cout << dp[i][1] << " ";
	}
	// cout << endl;
	for (int i = 2; i <= x; i++) {
		deque<pair<LL, LL> > dq;
		for (int j = 1; j <= n; j++) {
			int rg = j - k;	
			while (!dq.empty() && dq.front().second < rg)
				dq.pop_front();
			while (!dq.empty() && dq.back().first < dp[j - 1][i - 1])
				dq.pop_back();
			dq.pb({dp[j - 1][i - 1], j - 1});
			if (dq.front().first == -1)
				dp[j][i] = -1;
			else dp[j][i] = arr[j] + dq.front().first;
			// cout << dp[j][i] << " ";
		}
		// cout << endl;
	}
	LL ret = -1LL;
	for (int i = 0; i < k; i++) {
		LL now = n - i;
		ret = max(ret, dp[now][x]);
	}
	printf("%lld\n", ret);
	return 0;
}
		
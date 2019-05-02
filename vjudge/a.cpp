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

struct node {
	LL val, idx[4];
	node() {
		val = 0LL;
		for (int i = 0; i < 4; i++)
			idx[i] = -1;
	}
};

vector<LL> pq[4];
LL cnt[4];
node dp[300005];

int main() {
	SET(cnt, 0);
	LL n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		pq[a].pb(b);
		cnt[a]++;
	}
	sort(all(pq[1]), greater<LL>());
	sort(all(pq[2]), greater<LL>());
	sort(all(pq[3]), greater<LL>());
	LL ans = 0LL;
 	for (int i = 1; i <= m; i++) {
 		LL mx = -1;
 		for (int j =1; j <= 3; j++) {
	 		if (j > i)
	 			continue;
	 		if (dp[i - j].idx[j] == cnt[j] - 1)
	 			continue;
	 		if (dp[i - j].val + pq[j][dp[i - j].idx[j] + 1] > mx) {
	 			mx = pq[j][dp[i - j].idx[j] + 1] + dp[i - j].val;
	 			dp[i] = dp[i - j];
	 			dp[i].val = mx;
	 			dp[i].idx[j]++;
	 		}
	 		else if (dp[i - j].val + pq[j][dp[i - j].idx[j] + 1] == mx)
	 			continue;
	 	}
	 	// debug(mx);
	 	ans = max(ans, mx);
 	}
 	printf("%lld\n", ans);
	return 0;
}
	
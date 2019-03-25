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

LL prefix[1505];
map<LL, vector<LL> > last;
vector<LL> candidate;

int main() {
	last[0].pb(0);
	prefix[0] = 0LL;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		prefix[i] = prefix[i - 1] + a;
		last[prefix[i]].pb(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i - 1; j++) {
			candidate.pb(prefix[i] - prefix[j]);
		}
	}
	LL mx = 0;
	vector<pair<int, int> > ans;
	for (auto sum : candidate) {
		// debug(sum);
		LL dp[n + 1];
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			LL dest = prefix[i] - sum;
			if (last.find(dest) != last.end()) {
				for (auto x : last[dest]) {
					if (x >= i)
						continue;
					dp[i] = max(dp[i], dp[x] + 1);
				}
			}
			// cout << dp[i] << " ";
		}
		// cout << endl;
		if (dp[n] > ans.size()) {
			ans.clear();
			int now = n;
			while (now >= 0 && dp[now] > 0) {
				// debug(now);
				while (now > 0 && dp[now - 1] == dp[now])
					now--;
				LL cur = dp[now];
				LL nxt;
				for (auto x : last[prefix[now] - sum]) {
					if (dp[x] == cur - 1) {
						nxt = x;
						break;
					}
				}
				ans.pb({nxt + 1, now});
				now = nxt;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto it : ans) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}
		
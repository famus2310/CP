#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL voter[3005];
vector<LL> cost[3005];
vector<LL> targetVoter;
vector<LL> minVoter;

int main() {
	memset(voter, 0, sizeof voter);
	LL n, m;
	LL target = 0LL;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		voter[a]++;
		cost[a].pb(b);
		target = max(target, voter[a]);
	}
	for (int i = 1; i <= m; i++) {
		if (voter[i] == target) {
			targetVoter.pb(cost[i][0]);
			cost[i].erase(cost[i].begin());
		}
		for (int j : cost[i]) minVoter.pb(j);
	}
	sort(all(minVoter));
	sort(all(targetVoter));
	LL ans = 0LL;
	while (voter[1] != target && !targetVoter.empty()) {
		voter[1]++;
		ans += targetVoter[0];
		targetVoter.erase(targetVoter.begin());
	};
	while (voter[1] != target) {
		voter[1]++;
		ans += minVoter[0];
		minVoter.erase(minVoter.begin());
	}
	printf("%lld\n", ans);
	return 0;
}
		
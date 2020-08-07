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
	LL idx, val;
};

bool comp(node n1, node n2) {
	return n1.idx < n2.idx;
}

vector<pair<LL, LL > > adjList[N];
LL dp[N];
node arr[N];
map<int, int> mp;

void bfs() {
	SET(dp, 0);
	queue<LL> q;
	q.push(1);
	dp[1] = 1;
	while (!q.empty()) {
		mp.clear();
		int now = q.front();
		q.pop();
		for (auto it : adjList[now]) {
			if (dp[it.first])
				continue;
			dp[it.first] = max(dp[now], it.second);
			q.push(it.first);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, q;
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n ; i++)
			adjList[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adjList[a].pb({b, c});
			adjList[b].pb({a, c});
		}
		bfs();
		for (int i = 1; i <= n; i++) {
			int cur = dp[i];
			mp[cur] = i;
		}
		sort(dp + 1, dp + n + 1);
		LL ans = 0LL;
		for (int i = 0; i < q; i++) {
			int a;
			scanf("%d", &a);
			LL lb = lower_bound(dp + 1, dp + n + 1, a) - dp;
			// cout << lb << endl;
			lb--;
			// debug(mp[dp[lb]]);
			if (a == 1)
				ans++;
			else ans = ans + mp[dp[lb]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e6 + 5;

LL n, m, k;
vector<pair<LL, pair<LL, LL> > > edgeList;
bool vis[N];
vector<LL> selected;
LL dsu[N];

void init() {
	for (LL i = 0; i <= n; i++)
		dsu[i] = i;
}

LL findRoot(LL now) {
	if (dsu[now] != now)
		return dsu[now] = findRoot(dsu[now]);
	return now;
}

void uni(LL x, LL y) {
	LL root_x = findRoot(x);
	LL root_y = findRoot(y);
	dsu[root_x] = root_y;
}

LL kruskal() {
	LL ret = 0LL;
	for (LL i = 0; i < m; i++) {
		LL x = edgeList[i].second.first;
		LL y = edgeList[i].second.second;
		LL cost = edgeList[i].first;
		if (findRoot(x) != findRoot(y)) {
			vis[x] = vis[y] = 1;
			selected.pb(cost);
			ret += cost;
			uni(x, y);
		}
	}
	return ret;
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	init();
	for (LL i = 0; i < m; i++) {
		LL u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		edgeList.pb({w, {u, v}});
	}
	sort(all(edgeList));
	LL costNow = kruskal();
	for (LL i = 1; i <= n; i++) {
		if (!vis[i]) {
			puts("-1");
			return 0;
		}
	}
	sort(all(selected));
	LL ret = 0LL;
	while (!selected.empty() && costNow > k) {
		costNow -= selected.back();
		costNow++;
		ret++;
		selected.pop_back();
	}
	printf("%lld\n", costNow <= k ? ret : -1);
	return 0;
}

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

LL n, m;
vector<pair<LL, pair<LL, LL> > > edgeList;
LL par[N];

void init() {
	for (int i = 0; i < N; i++)
		par[i] = i;
}

LL findPar(LL now) {
	if (par[now] == now) return now;
	return par[now] = findPar(par[now]);
}

void uni(LL x, LL y) {
	LL par_x = findPar(x);
	LL par_y = findPar(y);
	par[par_x] = par_y;
}

LL kruskal() {
	LL ret = 0LL;
	for (int i = 0; i < m; i++) {
		LL u = edgeList[i].second.first;
		LL v = edgeList[i].second.second;
		LL cost = edgeList[i].first;
		LL par_u = findPar(u);
		LL par_v = findPar(v);
		if (par_u != par_v) {
			ret += cost;
			uni(par_u, par_v);
		}
	}
	return ret;
}

int main() {
	init();
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; i++) {
		LL u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		edgeList.pb({w, {u, v}});
	}
	sort(all(edgeList));
	LL ans = kruskal();
	printf("%lld\n", ans);
	return 0;
}
		
#include<iostream>
#include<vector>
#include<stdio.h>
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

vector<int> adjChild[6005];
LL par[6005];
LL val[6005];
LL n;
LL dp1[6005];
LL dp2[6005];

void dfs(LL now) {
	LL sum1 = 0;
	LL sum2 = 0;
	for (LL i = 0; i < adjChild[now].size(); i++) {
		LL it = adjChild[now][i];
		dfs(it);
		sum1 += dp2[it];
		sum2 += max(dp2[it], dp1[it]);
	}
	dp1[now] = val[now] + sum1;
	dp2[now] = sum2;
}

LL findRoot(LL now) {
	return par[now] == now ? now : findRoot(par[now]);
}
 
void preprocess() {
	for (int i = 0; i < 6005; i++) {
		par[i] = i;
		adjChild[i].clear();
	}
}

int main() {
	while (~scanf("%lld", &n)) {
		preprocess();
		for (int i = 1; i <= n; i++)
			scanf("%lld", val + i);
		LL a, b;
		while (~scanf("%lld %lld", &a, &b), a || b) {
			adjChild[b].pb(a);
			par[a] = b;
		}
		// debug("Cuk");
		LL root = findRoot(1);
		dfs(root);
		printf("%lld\n", max(dp1[root], dp2[root]));
	}
	return 0;
}
		
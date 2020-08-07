#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
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

unsigned long long k1, k2;

unsigned long long xorShift() {
	unsigned long long k3 = k1, k4 = k2;
	k1 = k4;
	k3 ^= k3 << 23;
	k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
	return k2 + k4;
}

struct edge {
	LL u, v, w;
};

bool comp (edge a, edge b) {
	return a.w < b.w;
}

LL n, m;
edge edgeList[N];

LL par[N];
LL rk[N];

void init() {
	for (int i = 0; i <= n; i++) {
		rk[i] = 0;
		par[i] = i;
	}
}

LL findRoot(LL x) {
	return par[x] == x ? x : par[x] = findRoot(par[x]);
}


int main() {
	LL t;
	scanf("%llu", &t);
	while (t--) {
		scanf("%llu %llu %llu %llu", &n, &m, &k1, &k2);
		init();
		for (LL i = 1; i <= m; i++) {
			edgeList[i].u = xorShift() % n + 1;
			edgeList[i].v = xorShift() % n + 1;
			edgeList[i].w = xorShift();
		}
		LL mst = 0LL;
		sort(edgeList + 1, edgeList + m + 1, comp);
		LL cnt = 0LL;
		for (LL i = 1; i <= m; i++) {
			LL par_u = findRoot(edgeList[i].u);
			LL par_v = findRoot(edgeList[i].v);
			if (par_u != par_v) {
				cnt++;
				if (rk[par_u] > rk[par_v])
					par[par_v] = par_u;
				else if (rk[par_u] < rk[par_v])
					par[par_u] = par_v;
				else {
					par[par_u] = par_v;
					rk[par_u]++;
				}
				mst = (mst + (edgeList[i].w % MOD)) % MOD;
			}
			if (cnt == n - 1) break;
		}
		if (cnt == n - 1)
			printf("%llu\n", mst % MOD);
		else puts("0");
	}
	return 0;
}
		
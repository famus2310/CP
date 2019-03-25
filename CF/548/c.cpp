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

vector<pair<int, int> > adjList[N];
LL par[N];
LL sz[N];
bool vis[N];
LL power[N][105];
LL n, k;

void init() {
	for (int i = 0; i < N; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}

LL findPar(LL x) {
	return par[x] == x ? x : par[x] = findPar(par[x]);
}

void uni(LL a, LL b) {
	LL roota = findPar(a);
	LL rootb = findPar(b);
	if (sz[roota] > sz[rootb]) {
		par[rootb] = roota;
		sz[roota] += sz[rootb];
	} else {
		par[roota] = rootb;
		sz[rootb] += sz[roota];
	}
}

int main() {
	init();
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
				if (i == 0)
					power[j][i] = 1;
				else
					power[j][i] = (power[j][i - 1] * j) % MOD; 
			}
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v, col;
		scanf("%d %d %d", &u, &v, &col);
		if (!col)
			uni(u, v);
	}
	LL red = 0LL;
	for (int i = 1; i <= n; i++) {
		LL root = findPar(i);
		// debug(sz[root]);
		// debug(root);
		red = (red + power[sz[root]][k - 1]) % MOD;
	}
	LL ans = (power[n][k] - red + MOD)% MOD;
	printf("%lld\n", ans);

	return 0;
}
		
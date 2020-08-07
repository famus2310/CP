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

LL parent[N];

LL findPar(LL now) {
	if (now == parent[now]) 
		return now;
	return parent[now] = findPar(parent[now]);
}

void uni(LL x, LL y) {
	LL parX = findPar(x);
	LL parY = findPar(y);
	parent[parX] = parY; 
}

void init() {
	for (int i = 0; i < N; i++)
		parent[i] = i;
}

int main() {
	init();
	scanf("%lld %lld", &n, &m);
	LL ans = -1;
	for (int i = 1; i <= m; i++) {
		LL u, v;
		scanf("%lld %lld", &u, &v);
		if (ans == -1) {
			LL parX = findPar(u);
			LL parY = findPar(v);
			if (parX == parY) ans = i;
			else parent[parX] = parY;
		} else continue;
	}
	printf("%lld\n", ans);
	return 0;
}
		
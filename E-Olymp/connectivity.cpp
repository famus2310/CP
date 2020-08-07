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

LL par[105];

void init() {
	for (int i = 0; i < 100; i++) par[i] = i;
}

LL findPar(LL x) {
	if (par[x] == x) return x;
	return par[x] = findPar(par[x]);
}

void merge(LL x, LL y) {
	par[findPar(x)] = findPar(y); 
}

int main() {
	init();
	LL n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; i++) {
		LL u, v;
		scanf("%lld %lld", &u, &v);
		merge(u, v);
	}
	set<LL> st;
	for (int i = 1; i <= n; i++) {
		st.insert(findPar(par[i]));
	}
	printf("%s", st.size() == 1 ? "YES\n" : "NO\n");
	return 0;
}
		
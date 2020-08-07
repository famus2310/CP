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

LL par0[2 * N];
LL par1[2 * N];
LL sz0[2 * N];
LL sz1[2 * N];

void init() {
	for (int i = 0; i < 2 * N; i++) {
		par0[i] = par1[i] = i;
		sz0[i] = sz1[i] = 1;
	}
}

LL findRoot0(LL x) {
	return par0[x] == x ? x : par0[x] = findRoot0(par0[x]);
}

LL findRoot1(LL x) {
	return par1[x] == x ? x : par1[x] = findRoot1(par1[x]);
}

void uni0(LL a, LL b) {
	LL roota = findRoot0(a);
	LL rootb = findRoot0(b);
	if (rootb != roota) {
		if (sz0[roota] < sz0[rootb])
			swap(roota, rootb);
		par0[rootb] = roota;
		sz0[roota] += sz0[rootb];
	}
}

void uni1(LL a, LL b) {
	LL roota = findRoot1(a);
	LL rootb = findRoot1(b);
	if (rootb != roota) {
		if (sz1[roota] < sz1[rootb])
			swap(roota, rootb);
		par1[rootb] = roota;
		sz1[roota] += sz1[rootb];
	}
}

int main() {
	fastio;
	init();
	LL n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		LL x, y, c;
		cin >> x >> y >> c;
		if (c == 0)
			uni0(x, y);
		else uni1(x, y);
	}
	LL ans = 0LL;
	for (LL i = 1; i <= n; i++) {
		LL rooti1 = findRoot1(i);
		LL rooti0 = findRoot0(i);
		ans = ans + sz1[rooti1] - 1;
		ans = ans + sz0[rooti0] - 1;
		ans = ans + (sz1[rooti1] - 1) * (sz0[rooti0] - 1);
	}
	cout << ans << endl;
	return 0;
}
		
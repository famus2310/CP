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

const int N = 2e5 + 5;

LL up[N], down[N];
LL arm[N];

int main() {
	for (LL i = 0; i < N; i++) {
		up[i] = 0;
		down[i] = 0;
		arm[i] = -1;
	}
	LL n, m;
	scanf("%lld %lld", &n, &m);
	for (LL i = 0; i < m; i++) {
		LL x, y;
		scanf("%lld %lld", &x, &y);
		arm[x] = y;
	}
	for (int i = 0; i < 100005; i++) {
		if (arm[i] == -1) continue;
		up[arm[i]] = up[arm[i] + 1] + 1;
		down[arm[i] + 1] = down[arm[i]] + 1;
	}
	for (LL i = 1; i <= n; i++) {
		printf("%lld%c", up[i] + down[i] + 1, i == n ? '\n' : ' ');
	}
	return 0;
}
		
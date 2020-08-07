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

LL f[35];
LL g[35];

int main() {
	f[0] = 1LL;
	f[1] = 0LL;
	g[0] = 1LL;
	g[1] = 0LL;
	for (LL i = 2; i <= 30; i++) {
		f[i] = f[i - 2] + 2LL * g[i - 2];
		g[i] = f[i] + g[i - 2];
	}
	LL n;
	while (scanf("%lld", &n) == 1 && n != -1) {
		printf("%lld\n", f[n]);
	}
	return 0;
}
		
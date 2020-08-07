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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL modex(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b / 2;
		a = (a * a) % MOD;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, a, r;
		scanf("%lld %lld %lld", &n, &a, &r);
		LL ans = 0LL;
		for (LL i = 1; i <= n; i++) {
			ans = (ans + (modex(a, i) * modex(i, r)) % MOD) % MOD;
			// debug(ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		
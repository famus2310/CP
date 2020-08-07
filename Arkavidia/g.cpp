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

LL mulmod(LL a, LL b) {
	LL ret = 0LL;
	while (b) {
		if (b & 1)
			ret = (ret + a) % MOD;
		b = b / 2;
		a = (a + a) % MOD;
	}
	return ret;
}

LL powmod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1)
			ret = mulmod(ret, a);
		b = b / 2;
		a = mulmod(a, a);
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n;
		scanf("%lld", &n);
		if (n == 1)
			puts("1");
		else {
			//formula: 3 * 10^(n - 1) - (8 * 3^ (2 * n - 3))) = 3 * 10 ^ (n - 1) - (14n - 24)
			LL a = (3 * powmod(10, n - 1)) % MOD;
			LL b = ( 8 * powmod(3, 2 * n - 3)) % MOD;
			LL ans = (a - b + MOD) % MOD;
			if (ans < 0)
				ans += MOD;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
		
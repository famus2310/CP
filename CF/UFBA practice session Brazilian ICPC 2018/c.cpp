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

LL powmod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b >> 1;
		a = (a * a) % MOD;
	}
	return ret;
}

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL n;
		scanf("%lld", &n);
		n -= 2;
		LL ans1 = ((n % MOD) + 5) % MOD;//n + 5 + (n - 1) * 2 ^ (n + 2)
		LL ans2 = (((n - 1) % MOD) * powmod(2, n + 2)) % MOD;
		LL ans = (ans1 + ans2) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
		
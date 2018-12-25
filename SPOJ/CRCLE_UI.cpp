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

LL factmod (LL n, LL p) {
	LL res = 1;
	while (n > 1) {
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		for (LL i = 2; i <= n % p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}

LL powmod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b >> 1;
		a = (a * a) % MOD;
	}
	return ret;
}

LL inverse(LL a) {
	return powmod(a, MOD - 2);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, k;
		scanf("%lld %lld", &n, &k);
		LL ans1 = (factmod(k, MOD) * factmod(n, MOD)) % MOD; 
		LL ans2 = (inverse(factmod(k - n, MOD)) * inverse(factmod(n, MOD))) % MOD;
		LL ans = (ans1 * ans2) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
		
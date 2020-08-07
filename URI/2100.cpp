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
const int MOD = 1300031;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL fact[4005];
LL power[4005];
void precomp() {
	fact[0] = power[0] = 1LL;
	for (LL i = 1; i < 4005; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		power[i] = (power[i - 1] * 2LL) % MOD;
	}
}

LL powmod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b / 2;
		a = (a * a) % MOD;
	}
	return ret;
}

LL inverse(LL a) {
	return powmod(a, MOD - 2);
}

int main() {
	precomp();
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL n, m;
		scanf("%lld %lld", &n, &m);
		LL ans = (fact[n - m] * power[m]) % MOD;
		ans = (ans * inverse(fact[n - 2 * m])) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
		
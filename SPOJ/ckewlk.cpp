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

LL modex(LL a, LL b) {
	LL ret = 1;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b >> 1;
		a = (a * a) % MOD;
	}
	return ret;
}

LL func(LL n, LL m) {
	if (n == 1 || n == 2) return m % MOD;
	return (modex(2, n - 2) * (m % MOD)) % MOD;
}

LL solve(LL n) {
	LL ret = -1;
	while (n % 2 == 0) {
		ret = 2;
		n = n >> 1;
	}
	for (int i = 3; i <= sqrt(n) && n > 1; i += 2) {
		while (n % i == 0) {
			ret = i;
			n /= i;
		}
	}
	if (n > 1) {
		ret = max(n, ret);
	}
	return ret;
}

int main() {
	LL t, m;
	scanf("%lld %lld", &t, &m);
	LL ans = 0;
	while (t--) {
		LL n;
		scanf("%lld", &n);
		LL f = func(n, m);
		LL c = solve(f + n % MOD + m % MOD) % MOD;
		ans += c;
	}
	printf("The President needs to pay %lld dollar(s)\n", ans);
	return 0;
}
		
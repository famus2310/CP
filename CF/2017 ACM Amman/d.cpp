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

LL fact[N];

LL powmod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b >> 1LL;
		a = (a * a) % MOD;
	}
	return ret;
}

LL inv(LL a) {
	return powmod(a, MOD - 2);
}

LL binomialCoeff(LL n, LL k) { 
    LL res = 1LL;
    res = (res * fact[n]) % MOD;
    res = (res * inv(fact[n - k])) % MOD;
    res = (res * inv(fact[k])) % MOD;
    return res; 
} 

void precompute() {
	fact[0] = fact[1] = 1LL;
	for (LL i = 2; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
}

int main() {
	precompute();
	int t;
	scanf("%d", &t);
	while (t--) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		a--;
		LL ans = (binomialCoeff(a, b) * 2LL) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
		
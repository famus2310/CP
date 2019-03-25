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
const int MOD = 1e9 + 9;
const int INF = 1e9 + 5;
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

LL inverse(LL a) {
	return modex(a, MOD - 2);
}


LL arr[N];

int main() {
	LL n;
	scanf("%lld", &n);
	LL k = 1LL;
	LL lcm = 1LL;

	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		k = (k * a) % MOD;
		LL gcd = __gcd(a, lcm);
		lcm = (lcm * a) % MOD;
		lcm = (lcm * inverse(gcd)) % MOD;
	}
	// printf("%lld %lld\n", k, lcm);
	LL ret = (k * inverse(lcm))% MOD;
	printf("%lld\n", ret);
	return 0;
}
		
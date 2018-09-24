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
 
LL mulmod(LL a, LL b, LL c) {
	LL ret = 0;
	while (b) {
		if (b & 1) ret = (ret + a) % c;
		b = b >> 1;
		a = (2 * a) % c;
	}
	return ret;
}
 
LL powmod(LL a, LL b, LL c) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (mulmod(ret, a, c)) % c;
		b = b >> 1;
		a = (mulmod(a, a, c)) % c;
	}
	return ret;
}
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL a, b, n;
		scanf("%lld %lld %lld", &a, &b, &n);
		LL x = a == b ? MOD : abs(a - b);	
		LL y1 = powmod(a, n, x);
		LL y2 = powmod(b, n, x);
		LL y = (y1 + y2) % x;
		LL ans;
		if (a != b) ans = __gcd(x, y);
		else ans = __gcd(0LL, y);
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
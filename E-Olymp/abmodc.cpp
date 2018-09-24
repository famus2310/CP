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

const int NMAX = 1e5 + 5;

LL modmult(LL a, LL b, LL c) {
	LL ret = 0;
	if (a == 0 || b < c / a) return (a * b) % c;
	while (b) {
		if (b & 1) ret = (ret + a) % c;
		b >>= 1;
		a = (2 * a) % c;
	}
	return ret;
}

LL powmod(LL a, LL b, LL c) {
	LL ret = 1;
	a %= c;
	while (b) {
		if (b & 1) ret = modmult(ret, a, c);
		b >>= 1;
		a = modmult(a, a, c);
	}
	return ret;
}

int main() {
	LL a, b, c;
	while (cin >> a >> b >> c) cout << powmod(a, b, c) << endl;
	return 0;
}
		
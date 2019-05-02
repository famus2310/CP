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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL power[65];

LL modex(LL a, LL b) {
	LL ret = 0LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b / 2;
		a = (a * a) % MOD;
	}
	return ret;
}

LL solveOdd(LL n) {
	return ((n % MOD) * (n % MOD)) % MOD;
}

LL solveEven(LL n) {
	return (((n + 1) % MOD) * (n % MOD)) % MOD;
}


LL solve(LL x) {
	LL ret = 0LL;
	if(x < 0)
		return 0;
	LL now = power[x];
	while (now) {
		ret = ret + now;
		now = now / 4;
	}
	return ret;
}

int main() {
	power[0] = 1;
	for (LL i = 1; i < 64; i++) 
		power[i] = power[i - 1] << 1LL;
	fastio;
	LL l, r;
	cin >> l >> r;
	l--;
	LL prefixR = 0;
	LL prefixL = 0;
	LL ridx = upper_bound(power, power + 64, r + 1) - power;
	LL lidx = upper_bound(power, power + 64, l + 1) - power;
	ridx--;
	lidx--;
	LL odd = 0LL;
	LL even = 0LL;
	LL rem = r - power[ridx] + 1;
	if (ridx & 1) {
		odd = solve(ridx - 1);
		even = solve(ridx - 2);
		even = even + rem;
	} else {
		odd = solve(ridx - 2);
		even = solve(ridx - 1);
		odd = odd + rem;
	}
	rem = l - power[lidx] + 1;
	// cout << "odd: " << odd << " even : " << even << endl;
	prefixR = (prefixR + (solveEven(even) + solveOdd(odd)) % MOD) % MOD;
	if (lidx & 1) {
		odd = solve(lidx - 1);
		even = solve(lidx - 2);
		even = even + rem;
	} else {
		odd = solve(lidx - 2);
		even = solve(lidx - 1);
		odd = odd + rem;
	}
	// cout << "odd: " << odd << " even : " << even << endl;
	prefixL = (prefixL + (solveEven(even) + solveOdd(odd)) % MOD) % MOD;
	// cout << prefixR << " " << prefixL << endl;
	cout << (prefixR - prefixL + MOD) % MOD << endl;
	return 0;
}
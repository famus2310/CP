#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

inline void scanint(long long &x) {
	register long long c = getchar_unlocked();
	x = 0;
	long long neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

LL modex(LL a, LL b, LL m) {
	a = a % m;
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % m;
		b = b >> 1LL;
		a = (a * a) % m;
	}
	if (ret == 0)
		ret = m;
	return ret;
}

int main() {
	LL t;
	scanint(t);
	while (t--) {
		LL a, b, m;
		scanint(a);
		scanint(b);
		scanint(m);
		printf("%lld\n", modex(a, b, m));
	}
	return 0;
}
		
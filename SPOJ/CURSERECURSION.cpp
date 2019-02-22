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

inline void scanint(long long int &x) {
	register long long int c = getchar_unlocked();
	x = 0;
	long long int neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

LL solve(LL x) {
	LL ret = 0LL;
	while (x % 2 == 0) {
		ret++;
		x /= 2;
	}
	return ret;
}

int main() {
	LL t;
	scanint(t);
	while (t--) {
		LL n, k;
		scanint(n);
		scanint(k);
		double rs = log2((double)k + 1.0);
		if ((double)n < rs)
			puts("0");
		else {
			LL ans = solve(k) + 1;
			printf("%lld\n", ans);
		}
	}

	return 0;
}
		
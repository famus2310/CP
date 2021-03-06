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

LL arr[N];

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

int main() {
	LL n, q;
	scanint(n);
	scanint(q);
	for (int i = 0; i < q; i++) {
		LL a, b, c;
		scanint(a);
		scanint(b);
		scanint(c);
		arr[a] = arr[a] + c;
		arr[b + 1] = arr[b + 1] - c;
	}
	LL now = 0LL;
	for (int i = 1; i <= n; i++) {
		if (i != 1)
			printf(" ");
		now = now + arr[i];
		printf("%lld", now);
	}
	puts("");
	return 0;
}
		
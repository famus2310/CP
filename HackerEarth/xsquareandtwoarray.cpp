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

LL oddA[N], evenA[N], oddB[N], evenB[N];

int main() {
	LL n, q;
	scanf("%lld %lld", &n, &q);
	oddA[0] = oddB[0] = evenB[0] = evenA[0] = 0;
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		oddA[i] = oddA[i - 1];
		evenA[i] = evenA[i - 1];
		if (i & 1) oddA[i] += a;
		else evenA[i] += a;
	}
	for (int i = 1; i <= n; i++) {
		LL b;
		scanf("%lld", &b);
		oddB[i] = oddB[i - 1];
		evenB[i] = evenB[i - 1];
		if (i & 1) oddB[i] += b;
		else evenB[i] += b;
	}
	while (q--) {
		LL x, l, r;
		scanf("%lld %lld %lld", &x, &l, &r);
		if (x == 1) {
			if (l & 1) printf("%lld\n", oddA[r] + evenB[r] - oddA[l - 1] - evenB[l - 1]);
			else printf("%lld\n", evenA[r] + oddB[r] - evenA[l - 1] - oddB[l - 1]);
		} else {
			if (l & 1) printf("%lld\n", oddB[r] + evenA[r] - oddB[l - 1] - evenA[l - 1]);
			else printf("%lld\n", evenB[r] + oddA[r] - evenB[l - 1] - oddA[l - 1]);
		}
	}
	return 0;
}
		
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

LL BITpos[N];
LL BITzero[N];

void upd(LL* BIT, int x, LL val) {
	for (; x < N; x += (x & -x))
		BIT[x] += val;
}

LL getSum(LL* BIT, int x) {
	if (x == 0)
		return 0LL;
	LL ret = 0LL;
	for (; x > 0; x -= (x & -x))
		ret += BIT[x];
	return ret;
}

LL query(LL* BIT, int a, int b) {
	if (a <= 1)
		return getSum(BIT, b);
	return getSum(BIT, b) - getSum(BIT, a - 1);
}

LL change(LL* BIT, int x, LL val) {
	upd(BIT, x, val - query(BIT, x, x));
}

int main() {
	LL n, k;
	while (scanf("%lld %lld", &n, &k) == 2) {
		SET(BITpos, 0);
		SET(BITzero, 0);
		for (int i = 1; i <= n; i++) {
			LL a;
			scanf("%lld", &a);
			if (a > 0)
				change(BITpos, i, 1);
			else if (a == 0)
				change(BITzero, i, 1);
		}
		while (k--) {
			char c;
			scanf(" %c", &c);
			if (c == 'C') {
				int idx;
				LL val;
				scanf("%d %lld", &idx, &val);
				if (val < 0) {
					if (query(BITpos, idx, idx) == 1) 
						change(BITpos, idx, 0);
					if (query(BITzero, idx, idx) == 1)
						change(BITzero, idx, 0);
				} else if (val > 0) {
					if (query(BITpos, idx, idx) == 0) 
						change(BITpos, idx, 1);
					if (query(BITzero, idx, idx) == 1)
						change(BITzero, idx, 0);
				} else if (val == 0) {
					if (query(BITpos, idx, idx) == 1) 
						change(BITpos, idx, 0);
					if (query(BITzero, idx, idx) == 0)
						change(BITzero, idx, 1);
				}
			} else {
				int a, b;
				scanf("%d %d", &a, &b);
				LL pos = query(BITpos, a, b);
				LL zero = query(BITzero, a, b);
				LL neg = (b - a + 1) - (pos + zero);
				// cout << pos << " " << zero << " " << neg << endl;
				if (zero > 0)
					printf("0");
				else if (neg & 1)
					printf("-");
				else printf("+");
			}
		}
		puts("");
	}
	return 0;
}
		
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

const int N = 1e6 + 5;

LL BIT[N];

void upd(int x, LL val) {
	for (; x < N; x += (x & -x))
		BIT[x] += val;
}

LL getSum(int x) {
	if (x == 0)
		return 0LL;
	LL ret = 0LL;
	for (; x > 0; x -= (x & -x))
		ret += BIT[x];
	return ret;
}

LL query(int a, int b) {
	if (a <= 1)
		return getSum(b);
	return getSum(b) - getSum(a - 1);
}

LL change(int x, LL val) {
	upd(x, val - query(x, x));
}

LL solve(LL x) {
	int lo = 0;
	int hi = N;
	while (hi - lo > 2) {
		LL mid = lo + (hi - lo) / 2;
		LL cur = getSum(mid);
		// cout << mid << " " << cur << endl;
		if (cur > x)
			hi = mid - 1;
		else if (cur < x)
			lo = mid;
		else if (cur == x)
			return mid;
	}
	if (hi < lo)
		swap(hi, lo);
	for (; hi >= lo; hi--) {
		LL cur = getSum(hi);
		if (cur <= x)
			return hi;
	}
}

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		change(i, a);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			LL val;
			scanf("%lld", &val);
			printf("%lld\n", min(solve(val), n));
		} else {
			int idx;
			LL val;
			scanf("%d %lld", &idx, &val);
			change(idx, val);
		}
	}
	return 0;
}
		
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

LL segTree[4 * N];
LL arr[N];

void build(LL node, LL st, LL en) {
	if (st == en) {
		segTree[node] = arr[st];
	} else {
		LL mid = st + (en - st) / 2;
		build(2 * node, st, mid);
		build(2 * node + 1, mid + 1, en);
		segTree[node] = __gcd(segTree[2 * node], segTree[2 * node + 1]); 
	}
}

void upd(LL node, LL st, LL en, LL idx, LL val) {
	if (st == en) {
		segTree[node] = val;
	}
	else {
		LL mid = st + (en - st) / 2;
		if (idx <= mid)
			upd(2 * node, st, mid, idx, val);
		else
			upd(2 * node + 1, mid + 1, en, idx, val);
		segTree[node] = __gcd(segTree[2 * node], segTree[2 * node + 1]); 
	}
}

LL query(LL node, LL st, LL en, LL lo, LL hi) {
	if (st > hi || en < lo) {
		return 0;
	}
	else if (lo <= st && en <= hi) {
		return segTree[node];
	}
	else {
		LL mid = st + (en - st) / 2;
		LL q1 = query(2 * node, st, mid, lo, hi);
		LL q2 = query(2 * node + 1, mid + 1, en, lo, hi);
		return __gcd(q1, q2);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (LL i = 1; i <= n; i++) {
		scanf("%lld", arr + i);
	}
	build(1, 1, n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			LL a, b;
			scanf("%lld %lld", &a, &b);
			LL q1 = query(1, 1, n, a, b);
			printf("%lld\n", q1	);
		} else {
			LL a, b;
			scanf("%lld %lld", &a, &b);
			upd(1, 1, n, a, b);
		}
	}
 	return 0;
}

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

LL segTree[4 * N][2];
LL arr[N];

void build(LL node, LL st, LL en) {
	if (st == en) {
		segTree[node][0] = arr[st];
		segTree[node][1] = arr[st];
	} else {
		LL mid = st + (en - st) / 2;
		build(2 * node, st, mid);
		build(2 * node + 1, mid + 1, en);
		segTree[node][0] = min(segTree[2 * node][0], segTree[2 * node + 1][0]);
		segTree[node][1] = max(segTree[2 * node][1], segTree[2 * node + 1][1]); 
	}
}

void upd(LL node, LL st, LL en, LL idx, LL val) {
	if (st == en) {
		segTree[node][0] = val;
		segTree[node][1] = val;
	}
	else {
		LL mid = st + (en - st) / 2;
		if (idx <= mid)
			upd(2 * node, st, mid, idx, val);
		else
			upd(2 * node + 1, mid + 1, en, idx, val);
		segTree[node][0] = min(segTree[2 * node][0], segTree[2 * node + 1][0]);
		segTree[node][1] = max(segTree[2 * node][1], segTree[2 * node + 1][1]); 
	}
}

pair<LL, LL> query(LL node, LL st, LL en, LL lo, LL hi) {
	if (st > hi || en < lo) {
		return {INF, -INF};
	}
	else if (lo <= st && en <= hi) {
		return {segTree[node][0], segTree[node][1]};
	}
	else {
		LL mid = st + (en - st) / 2;
		pair<LL, LL> q1 = query(2 * node, st, mid, lo, hi);
		pair<LL, LL> q2 = query(2 * node + 1, mid + 1, en, lo, hi);
		return {min(q1.first, q2.first), max(q1.second, q2.second)};
	}
}

int main() {
	int q;
	scanf("%d", &q);
	for (LL i = 1; i < N; i++) {
		arr[i] = ((i * i) % 12345) + ((i * i * i) % 23456);
	}
	build(1, 1, N - 1);
	while (q--) {
		LL x, y;
		scanf("%lld %lld", &x, &y);
		if (x > 0) {
			pair<LL, LL> ans = query(1, 1, N - 1, x, y);
			printf("%lld\n", ans.second - ans.first);
		} else {
			upd(1, 1, N - 1, -x, y);
		}
	}
 	return 0;
}
		
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

LL segTree[3 * N], diff[3 * N], maxTree[3 * N], arr[N];

void build(LL node, LL l, LL r) {
	if (l == r) {
		segTree[node] = true;
		maxTree[node] = diff[l];
	} else {
		LL mid = l + (r - l) / 2;
		build(2 * node, l, mid);
		build(2 * node + 1, mid + 1, r);
		segTree[node] = segTree[2 * node] && segTree[2 * node + 1];
		if (maxTree[2 * node] != maxTree[2 * node + 1]) {
			segTree[node] = false;
		}
		maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
	}
}

void upd(LL node, LL l, LL r, LL val, LL idx) {
	if (l > idx || r < idx) return;
	else if (l == r && l == idx) {
		segTree[node] = true;
		maxTree[node] = val;
		diff[idx] = val;
	} else {
		LL mid = l + (r - l) / 2;
		upd(2 * node, l, mid, val, idx);
		upd(2 * node + 1, mid + 1, r, val, idx);
		segTree[node] = segTree[2 * node] && segTree[2 * node + 1];
		if (maxTree[2 * node] != maxTree[2 * node + 1])
			segTree[node] = false;
		maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
 	}
}

bool query(LL node, LL l, LL r, LL a, LL b) {
	cout << l << " " << r << " " << segTree[node] << endl;
	if (l > r || a > r || b < l) return true;
	else if (a <= l && r <= b) {
		return segTree[node];
	} else {
		LL mid = l + (r - l) / 2;
		if (maxTree[2 * node] != maxTree[2 * node + 1]) return false;
		return query(2 * node, l, mid, a, b) && query(2 * node + 1, mid + 1, r, a, b);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(segTree, 0, sizeof(segTree));
		memset(diff, 0, sizeof(diff));
		memset(maxTree, 0, sizeof(maxTree));
		int n, q;
		scanf("%d %d", &n, &q);
		diff[0] = 0LL;
		for (int i = 0; i < n; i++) {
			scanf("%lld", arr + i);
			if (i == 0) continue;
			diff[i] = arr[i] - arr[i - 1];
		}
		build(1, 0, n - 1);
		while (q--) {
			int type;
			scanf("%d", &type);
			if (type == 1) {
				LL u, v;
				scanf("%lld %lld", &u, &v);
				upd(1, 0, n - 1, v - arr[u - 2], u - 1);
				upd(1, 0, n - 1, arr[u] - v, u);
				arr[u - 1] = v;
			} else {
				LL u, v;
				scanf("%lld %lld", &u, &v);
				printf("%s\n", query(1, 0, n - 1, u, v - 1) ? "YES" : "NO");
				for (int i = u; i < v; i++) cout << diff[i];
				puts("");
			}
		}
	}
	return 0;
}
		
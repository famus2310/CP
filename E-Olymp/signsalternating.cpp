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

LL BITodd[N]; // i = until 2 * i - 1;
LL BITeven[N]; // i = until 2 * i

void upd(LL* BIT, int x, LL val) {
	for (; x < N; x += (x & -x))
		BIT[x] += val;
}

LL getSum(LL* BIT, int x) {
	LL ret = 0LL;
	for (; x > 0; x -= (x & -x))
		ret += BIT[x];
	return ret;
}

LL query(LL* BIT, int a, int b) {
	if (a > b)
		swap(a, b);
	if (a <= 1)
		return getSum(BIT, b);
	return getSum(BIT, b) - getSum(BIT, a - 1);
}

LL change(LL* BIT, int a, LL val) {
	upd(BIT, a, val - query(BIT, a, a));
}

int main() {
	SET(BITodd, 0);
	SET(BITeven, 0);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		if (i & 1)
			upd(BITodd, i, a);
		else upd(BITeven, i, a);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 0) {
			int idx;
			LL a;
			scanf("%d %lld", &idx, &a);
			if (idx & 1)
				change(BITodd, idx, a);
			else change(BITeven, idx, a);
		} else {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a & 1) {
				// cout << query(BITodd, (a + 1) / 2, (b + 1) / 2) << " " << query(BITeven, a / 2, b / 2) << endl;
				printf("%lld\n", query(BITodd, a, b) - query(BITeven, a, b));
			}
			else { 
				// cout << query(BITeven, a / 2, b / 2) << " " << query(BITodd, (a + 2) / 2, (b + 1) / 2) << endl;
				printf("%lld\n", query(BITeven, a, b) - query(BITodd, a, b));
			}
		}
	}
	return 0;
}

//odd: 1 = 1, 2 = 1, 3 = 2, 3 = 5, n = 2 * i - 1
//even: 1 = 0, 2 = 1, 3 = 1
		
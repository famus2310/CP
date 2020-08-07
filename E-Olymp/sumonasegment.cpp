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

LL BIT[N];

void upd(int x, LL val) {
	for (; x < N; x += (x & -x))
		BIT[x] += val;
}

LL getSum(int x) {
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


int main() {
	SET(BIT, 0);
	int n, q;
	scanf("%d %d", &n, &q);
	while (q--) {
		char c;
		scanf(" %c", &c);
		if (c == 'A') {
			int a;
			LL b;
			scanf("%d %lld", &a, &b);
			change(a, b);
		} else {
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(a, b));
		}
	}
	return 0;
}
		
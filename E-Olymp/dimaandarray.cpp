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

const int N = 5e5 + 5;

int n, q;
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

LL query(int x, int y) {
	if (x > y) 
		swap(x, y);
	if (x == 1)
		return getSum(y);
	return getSum(y) - getSum(x - 1);
}


int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		upd(i + 1, a);
	}
	while (q--) {
		char c;
		scanf(" %c", &c);
		if (c == '=') {
			int a;
			LL b;
			scanf("%d %lld", &a, &b);
			upd(a, b - query(a, a));
		} else {
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(a, b));
		}
	}
	return 0;
}
		
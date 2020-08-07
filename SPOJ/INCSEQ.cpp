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

LL BIT[N][55];
LL zero = 0;

LL m = 5000000;

void upd(LL x, LL k, LL val) {
	for (; x < N; x += x & (-x))
		BIT[x][k] = (BIT[x][k] + val);
}

LL getSum(LL x, LL k) {
	LL ret = 0LL;
	for (; x; x -= x & (-x))
		ret = (ret + BIT[x][k]) % m;
	return ret % m;
}

int main() {
	memset(BIT, 0, sizeof BIT);
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		if (a == 0) {
			zero++;
			continue;
		}
		for (LL j = 49; j > 1; j--) {
			upd(a, j + 1, getSum(a - 1, j));
		}
		upd(a, 2, getSum(a - 1, 1) + zero);
		upd(a, 1, 1);
	}
	LL ans = getSum(N, k);
	if (k == 1) ans = (ans + zero) % m;
	printf("%lld\n", ans % m);
	return 0;
}
		
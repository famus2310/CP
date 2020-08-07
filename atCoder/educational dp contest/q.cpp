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

LL BIT[2 * N];
LL height[2 * N];
LL beauty[2 * N];

LL upd(LL x, LL val) {
	for(; x < 2 * N; x += x & (-x))
		BIT[x] = max(val, BIT[x]);
}

LL getMax(LL x) {
	LL ret = 0LL;
	for(; x > 0; x -= x & (-x))
		ret = max(BIT[x], ret);
	return ret;
}

int main() {
	SET(BIT, 0);
	int n;
	scanf("%d", &n);
	LL ans = 0LL;
	for (int i = 0; i < n; i++) 
		scanf("%lld", height + i);
	for (int i = 0; i < n; i++)
		scanf("%lld", beauty + i);
	for (int i = 0; i < n; i++) {
		LL mx = getMax(height[i] - 1);
		mx += beauty[i];
		upd(height[i], mx);
		ans = max(ans, mx);
	}
	printf("%lld\n", ans);
	return 0;
}
		
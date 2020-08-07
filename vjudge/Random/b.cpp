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

unordered_map<LL, LL> mp;

LL solve(LL x) {
	LL ret = 0LL;
	LL div = 5LL;
	while (x >= div) {
		ret += x / div;
		div *= 5;
	}
	return ret;
}

// void preprocess() {
// 	LL now = 0LL;
// 	LL cur = 5LL;
// 	LL add = 0LL;
// 	for (LL i = 5; now < (LL)1e8; i += 5) {
// 		if (i >= cur) {
// 			add++;
// 			cur *= 5;
// 		}
// 		now += add;
// 		if (mp.count(now) == 0)
// 			mp[now] = i;
// 		// debug(now);
// 	}
// }

int main() {
	// preprocess();
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL q;
		scanf("%lld", &q);
		LL lo = 5;
		LL hi = 1e18;
		LL ans = -1;
		while (lo < hi) {
			LL mid = lo + (hi - lo) / 2;
			if (solve(mid) == q) {
				ans = mid;
				break;
			} else if (solve(mid) < q) 
				lo = mid + 1;
			else hi = mid - 1;
		}	
		printf("Case %d: ", tc);

		if (ans == -1)
			puts("impossible");
		else {
			ans = ans - ans % 5;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
		
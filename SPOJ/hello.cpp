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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int main() {
	LL m, n;
	scanf("%lld %lld", &m, &n);
	for (int i = 0; i < n; i++) {
		LL la, ra, pa, lb, rb, pb;
		scanf("%lld %lld %lld %lld %lld %lld", &la, &ra, &pa, &lb, &rb, &pb);
		// LL lo = 0;
		// LL hi = m;
		// LL mid1;
		// LL mid2;
		// LL rep = 10;
		// for (int i = 0; i <= m; i++) {
		// 	double ans1 = (la <= i && i <= ra ? i : 0) * (double)((double)pa / 100.0) +
		// 	(lb <= m - i && m - i <= rb ? m - i : 0) * (double)((double)pb / 100.0);
		// 	cout << ans1 << " " << endl;
		// }
		// while (rep--) {
		// 	mid1 = lo + (hi - lo) / 3;
		// 	mid2 = lo + 2 * (hi - lo) / 3;
		// 	cout << mid1 << " " << mid2 << endl;
		// 	double ans1 = (la <= mid1 && mid1 <= ra ? mid1 : 0) * (double)((double)pa / 100.0) +
		// 	(lb <= m - mid1 && m - mid1 <= rb ? m - mid1 : 0) * (double)((double)pb / 100.0);
		// 	double ans2 = (la <= mid2 && mid2 <= ra ? mid2 : 0) * (double)((double)pa / 100.0) +
		// 	(lb <= m - mid2 && m - mid2 <= rb ? m - mid2 : 0) * (double)((double)pb / 100.0);
		// 	cout << ans1 << " " << ans2 << endl;
		// 	cout << endl;
		// 	if (ans1 > ans2) {
		// 		hi = mid2;
		// 	} else lo = mid1;
		// }	
		LL mid1 = min(ra, m);
		LL mid2 = min(rb, m - mid1);
		double ans1 = (la <= mid1 && mid1 <= ra ? mid1 : 0) * (double)((double)pa / 100.0) +
			(lb <= mid2 && mid2 <= rb ? mid2 : 0) * (double)((double)pb / 100.0);
		mid1 = min(la, m);
		mid2 = min(rb, m - mid1);
		double ans2 = (la <= mid1 && mid1 <= ra ? mid1 : 0) * (double)((double)pa / 100.0) +
			(lb <= mid2 && mid2 <= rb ? mid2 : 0) * (double)((double)pb / 100.0);
		mid1 = min(rb, m);
		mid2 = min(ra, m - mid1);
		double ans3 = (lb <= mid1 && mid1 <= rb ? mid1 : 0) * (double)((double)pb / 100.0) +
			(la <= mid2 && mid2 <= ra ? mid2 : 0) * (double)((double)pa / 100.0);
		mid1 = min(lb, m);
		mid2 = min(ra, m - mid1);
		double ans4 = (lb <= mid1 && mid1 <= rb ? mid1 : 0) * (double)((double)pb / 100.0) +
			(la <= mid2 && mid2 <= ra ? mid2 : 0) * (double)((double)pa / 100.0);
		// cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
		printf("%.9lf\n", (double)m + max(max(ans1, ans2), max(ans3, ans4)));
	}
	return 0;
}
/*
100
3
1 50 5 1 51 10
70 200 100 30 95 110
179 239 40 109 140 31
*/
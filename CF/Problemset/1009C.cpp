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


int main() {
	LL n, m;
	scanf("%lld %lld", &n, &m);
	LL sum = 0LL;
	LL mx = -INF64;
	LL mn = INF64;
	for (int i = 1; i <= n; i++) {
		LL l = 1LL * (n - i) * (n - i + 1) / 2;
		LL r = 1LL * (i - 1) * (i) / 2;
		mx = max(mx, l + r);
		mn = min(mn, l + r);
	}
	for (int i = 0; i < m; i++) {
		LL x, d;
		scanf("%lld %lld", &x, &d);
		sum += x * n;
		if (d >= 0) {
			// sum += d * (n - 1) * n / 2;
			sum += d * mx;
		} else {
			sum += d * mn;
			// int tmp = n / 2;
			// sum += d * (tmp - 1) * tmp + (tmp % 2 == 0 ? -tmp : 0);
		}
	}
	double ans = (double) sum / (double) n;
	printf("%.10lf\n", ans);
	return 0;
}
		
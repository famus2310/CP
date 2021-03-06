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
	LL n, h, a, b, k;
	scanf("%lld %lld %lld %lld %lld", &n, &h, &a, &b, &k);
	for (int i = 0; i < k; i++) {
		LL xi, yi, xj, yj, ans = 0LL;
		scanf("%lld %lld %lld %lld", &xi, &yi, &xj, &yj);
		if (xi != xj) {
			if (yi > b) {
				ans += yi - b;
				yi = b;
			} else if (yi < a) {
				ans += a - yi;
				yi = a;
			}
		}
		ans += abs(xi - xj) + abs(yi - yj);
		printf("%lld\n", ans);
	}
	return 0;
}
		
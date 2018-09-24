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

LL arr[55];
vector<LL> lf, rg;

int main() {
	LL n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	int mid = n >> 1;
	for (int i = 0; i < (1 << mid); i++) {
		LL now = 0LL;
		for (int j = 0; j < mid; j++) {
			if ((1 << j) & i) {
				now += arr[j];
			}
		}
		lf.pb(now % m);
	}
	for (int i = 0; i < (1 << (n - mid)); i++) {
		LL now = 0LL;
		for (int j = 0; j < n - mid; j++) {
			if ((1 << j) & i) {
				now += arr[mid + j];
			}
		}
		rg.pb(now % m);
	}
	sort(all(lf));
	sort(all(rg));
	LL ans = 0LL;
	for (LL it : lf) {
		LL key = m - it - 1;
		LL ub = upper_bound(all(rg), key) - rg.begin();
		ans = max(ans, (it + rg[ub - 1]) % m);
	}
	printf("%lld\n", ans);
	return 0;
}
			
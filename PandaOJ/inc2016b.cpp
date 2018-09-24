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

int t, n;
LL k, arr[1005];

int main() {
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL mx = -1;
		scanf("%d %lld", &n, &k);
		for (int i = 0; i < n; i++) scanf("%lld", arr + i);
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			LL ub = upper_bound(arr + i, arr + n, arr[i] + k) - arr;
			mx = max(mx, ub - i);
		}
		printf("Case #%d: %lld\n", tc, mx);
	}
	return 0;
}
		
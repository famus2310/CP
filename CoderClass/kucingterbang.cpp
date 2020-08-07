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

LL arr[N], BIT[N];

void update(LL x, LL val) {
	arr[x] += val;
	while (x < N) {
		BIT[x] += val;
		x += x & -x;
	}
}

LL query(LL x) {
	LL ret = 0LL;
	while (x > 0) {
		ret = (ret + BIT[x]);
		x -= x & -x;
	}
	return ret;
}

int main() {
	memset(BIT, 0, sizeof BIT);
	memset(arr, 0, sizeof arr);
	int n;
	scanf("%d", &n);
	LL ans = 0LL;
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		LL now = (1LL + query(a));
		// debug(now);
		ans = (ans + now % MOD) % MOD;
		update(a, now - arr[a]);
	}
	printf("%lld\n", ans % MOD);
	return 0;
}
		
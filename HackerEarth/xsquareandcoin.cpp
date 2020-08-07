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

LL t;

int main() {
	scanf("%lld", &t);
	while (t--) {
		LL n, k;
		scanf("%lld %lld", &n, &k);
		LL now = 0;
		LL mx = 0;
		for (int i = 0; i < n; i++) {
			LL a;
			scanf("%lld", &a);
			if (a <= k) now += a;
			else now = 0;
			mx = max(mx, now);
		}
		printf("%lld\n", mx);
	}
	return 0;
}
		
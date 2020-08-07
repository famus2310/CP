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

LL fack(LL n, LL k) {
	LL ret = 1;
	LL i = 0LL;
	while (i * k < n) {
		if (ret > INF64 / (n - i * k)) return 0;
		ret *= (n - i * k);
		i++;
	}
	return ret;
}

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	LL ans = fack(n, k);
	if (ans == 0) 
		puts("overflow");
	else 
		printf("%lld\n", ans);
	return 0;
}
		
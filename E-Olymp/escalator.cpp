#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
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
	LL n;
	scanf("%lld", &n);
	LL now = 1;
	LL ans = 1;
	LL dig = 1;
	while (now < n) {
		ans += (dig - 1) * (now - now / 10);
		now = now * 10;
		dig++;
	}
	debug(ans);	
	dig--;
	now = now / 10;
	ans += dig * (n - now);
	if (ans % 10 != 0) ans += dig;
	printf("%lld\n", ans);	
	return 0;
}
		
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

LL PowMod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (a * ret) % MOD;
		b = b >> 1LL;
		a = (a * a) % MOD;
	}
	return ret;
}

int main() {
	LL n;
	scanf("%lld", &n);
	if (n < 4)
		printf("%lld\n", n);
	else if (n % 3 == 0) 
		printf("%lld\n", PowMod(3, (n / 3)));
	else if (n % 3 == 1)
		printf("%lld\n", (4 * PowMod(3, (n / 3) - 1)) % MOD);
	else 
		printf("%lld\n", (2 * PowMod(3, n / 3)) % MOD); 
	return 0;
}
		
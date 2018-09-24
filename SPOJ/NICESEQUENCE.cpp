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

LL modex(LL a, LL b) {
	LL ret = 1;
	while (b) {
		if (b & 1) ret = (a * ret) % MOD;
		b = b >> 1;
		a = (a * a) % MOD; 
	}
	return ret;
}

int main() {
	LL n;
	LL t;
	scanf("%lld", &t);
	while (t--){
		scanf("%lld", &n);
		LL ans = (1 + modex(5, n - 1) + modex(4, n - 1) + modex(3, n - 1) + modex(2, n - 1) + modex(2 , n - 1) + modex(2, n - 1) 
					+ modex(2, n - 1) + modex(2, n - 1)) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
		
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

LL power(LL a, LL b) {
	LL ret = 1;
	while (b) {
		if (b & 1) ret = ret * a;
		b = b >> 1;
		a = a * a;
	}
	return ret;
}

int main() {
	LL n, a, sum = 0;
	scanf("%lld %lld", &n, &a);
	if (a == 1) sum = (n * (n + 1)) / 2;
	else {
		for (LL i = 1; i <= n; i++) {
			sum += i * power(a, i);
		}
	}
	printf("%lld\n", sum);
	return 0;
}
		
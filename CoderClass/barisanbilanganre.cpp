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

LL bs(LL n, LL a, LL b) {
	LL lo = 1;
	LL hi = 1e18;
	LL mid;
	LL lcm = (a * b) / __gcd(a, b);
	while (lo < hi) {
		mid = (lo + (hi - lo) / 2);
		LL now = (mid / a) + (mid / b) - (mid / lcm);
		if (now > n) hi = mid - 1;
		else if (now < n) lo = mid + 1;
		else break;
	}
	while (mid % a && mid % b) mid--;
	return mid;
}

int main() {
	LL n, a, b;
	scanf("%lld %lld %lld", &n, &a, &b);
	printf("%lld\n", bs(n, a, b));
	return 0;
}
		
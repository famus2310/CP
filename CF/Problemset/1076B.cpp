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

LL check(LL x) {
	for (LL i = 2; i * i <= x; i++) {
		if (x % i == 0) return i;
	}
	return 0;
}

int main() {
	LL n;
	scanf("%lld", &n);
	if (check(n) == 0)
		puts("1");
	else if (n % 2 == 0)
		printf("%lld\n", n / 2);
	else {
		n -= check(n);
		printf("%lld\n", n / 2 + 1);
	}

	return 0;
}
		
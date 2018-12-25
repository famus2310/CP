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

bool notPrime[N];

LL sieve(LL x) {
	LL ret = 0LL;
 	for (LL i = 2; i <= x; i++) {
		for (LL j = 2 * i; j <= x; j += i) {
			ret += (j / i) * 4LL;
		}
 	}
 	return ret;
}

int main() {
	LL n;
	scanf("%lld", &n);
	printf("%lld\n", sieve(n));
	return 0;
}
		
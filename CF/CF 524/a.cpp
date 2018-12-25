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

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	LL a = n * 2;
	LL b = n * 5;
	LL c = n * 8;
	a = a / k + (LL)(a % k != 0);
	b = b / k + (LL)(b % k != 0);
	c = c / k + (LL)(c % k != 0);
	printf("%lld\n", a + b + c);
	return 0;
}
		
#include <iostream>
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

LL power[35];

int main() {
	LL now = 1LL;
	power[0] = now;
	for (int i = 1; i < 33; i++) {
		power[i] = (power[i - 1] * 2);
	}
	LL n, m;
	scanf("%lld %lld", &n, &m);
	if (n > 33)
		printf("%lld\n", m);
	else printf("%lld\n", m % power[n]);
	return 0;
}
		
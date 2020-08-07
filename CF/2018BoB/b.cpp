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
	LL t;
	scanf("%lld", &t);
	for (int tc = 1; tc <= t; tc++) {
		double m, d;
		scanf("%lf %lf", &m, &d);
		double v = m / d;
		double r = pow((3.0 * v / (4.0 * PI)), 1.0/3.0);
		double ans = 4.0 * PI * r * r;
		printf("Case %d: %.4lf\n", tc, ans);
	}
	return 0;
}
		
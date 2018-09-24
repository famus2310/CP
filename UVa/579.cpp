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
	double h, m;
	while (scanf("%lf:%lf", &h, &m), h || m) {
		// cout << h << " " << m << endl;
		double minuteDegree = 6.0 * m;
		double hourDegree = 30.0 * h + (1.0 / 12.0) * minuteDegree;
		// cout << minuteDegree << " " << hourDegree << endl;
		double degree = abs(minuteDegree - hourDegree);
		double ans = min(degree, 360 - degree);
		cout << setprecision(3) << fixed << ans << endl;
	}
	return 0;
}
		
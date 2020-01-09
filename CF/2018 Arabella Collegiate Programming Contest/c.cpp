#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

double a, b, c, percent;

double dist(double x, double y) {
	return sqrt(x * x + y * y);
}

double solve(double x, double y, double up) {
	double lo = x / (x + y) * up;
	return dist(x, lo) + dist(up - lo, y);
}

int main() {
	// NeedForSpeed;
	int t;
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		// cin >> a >> b >> c >> percent;
		scanf("%lf %lf %lf %lf", &a, &b, &c, &percent);
		double distOri = dist(a, b);
		double xpercent = distOri * percent / 100.0;
		double ratio = (distOri - xpercent) / distOri;
		double ya = a * ratio;
		double xaa = b * ratio; 
		double ans = solve(b + c, c, a) + distOri * percent / 100.0 + solve(xaa + c, c, ya);
		// cout << fixed << setprecision(9) << ans << endl;
		printf("%.9lf\n", ans);
	}
	return 0;
}
		
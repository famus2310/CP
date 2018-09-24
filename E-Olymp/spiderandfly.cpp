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

const int NMAX = 1e5 + 5;

double dist(double x1, double y1, double x2, double  y2, double z2) {
	return(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z2 * z2)));
}

int main() {
	LL a, b, c;
	cin >> a >> b >> c;
	double x1, y1, x2, y2, z2;
	cin >> x1 >> y1 >> x2 >> y2 >> z2;
	cout << setprecision(2) << fixed << dist(x1, y1, x2, y2, z2) << endl;
	return 0;
}
		
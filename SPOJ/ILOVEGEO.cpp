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

struct PT {
	double x, y;
};

double PTP(PT p1, PT p2) {
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return sqrt(x * x + y * y);
}

double PTL(PT p1, PT p2, PT p3) { //p1 to line p2 -> p3
	double isValid = (p2.x - p1.x) * (p3.x - p2.x) + (p2.y - p1.y) * (p3.y - p2.y);
	isValid /= -((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
	if (isValid > 1.0 || isValid < 0.0) return 1e9;
	double ly = p3.y - p2.y;
	double lx = p3.x - p2.x;
	double ans1 = ly * p1.x - lx * p1.y - ly * p2.x + lx * p2.y;
	double ans2 = sqrt(ly * ly + lx * lx);
	return abs(ans1 / ans2);
}

PT inner[105], outer[105];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			double a, b;
			scanf("%lf %lf", &a, &b);
			inner[i] = {a, b};
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			double a, b;
			scanf("%lf %lf", &a, &b);
			outer[i] = {a, b};
		}
		double ans = 1e9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				PT p1 = inner[i];
				PT p2 = outer[j];
				PT p3 = (j == m - 1 ? outer[0] : outer[j + 1]);
				double ans1 = PTP(p1, p2);
				double ans2 = PTL(p1, p2, p3);
				// cout << "point: " << p1.x << " " << p1.y << " " << p2.x <<" " << p2.y << " " << p3.x << " " << p3.y << endl;
				// cout << ans1 << " " << ans2 << endl;
				ans = min(ans, min(ans1, ans2));
			}
 		}
 		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				PT p1 = outer[i];
				PT p2 = inner[j];
				PT p3 = (j == n - 1 ? inner[0] : inner[j + 1]);
				double ans1 = PTP(p1, p2);
				double ans2 = PTL(p1, p2, p3);
				// cout << "point: " << p1.x << " " << p1.y << " " << p2.x <<" " << p2.y << " " << p3.x << " " << p3.y << endl;
				// cout << ans1 << " " << ans2 << endl;
				ans = min(ans, min(ans1, ans2));
			}
 		}
 		printf("%.6lf\n", ans);
 		
	}
	return 0;
}
		
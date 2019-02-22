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
	double h, w, f;
	while (scanf("%lf %lf %lf", &h, &w, &f), h || w || f) {
		printf("%.3lf\n", (f * f - 1.0) * w * w / (16.0 * h) + 0.000001);
	}
	return 0;
}
		
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
	int t;
	scanf("%d", &t);
	while (t--) {
		double x;
		scanf("%lf", &x);
		printf("%.13lf\n", (x + 9.0) / 9.0 - (1.0 * 2.0 * 3.0 * 4.0 * 5.0 * 6.0 * 7.0 * 8.0 / 
			((x + 1.0) * (x + 2.0) * (x + 3.0) * (x + 4.0) * (x + 5.0) * (x + 6.0) * (x + 7.0) * (x + 8.0))));
	}
	return 0;
}
		
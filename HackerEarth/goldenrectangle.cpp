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
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		double rat = a / b;
		// debug(a / b);
		if (1.6 <= rat && rat <= 1.7 || 1.6 <= 1.0 / rat && 1.0 / rat <= 1.7)
			ans++;
		// debug(ans);
	}
	printf("%d\n", ans);
	return 0;
}
		
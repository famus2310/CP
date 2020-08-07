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

const int N = 1e5 + 5;


int main() {
	int a, b, c, d;
	while (scanf("%d %d %d %d", &a, &b, &c, &d), (a || b || c || d)) {
		int ans = 0;
		ans += 720;
		int tmp = b - a < 0 ? 40 + (a - b) : a - b;
		ans += tmp * 9;
		ans += 360;
		tmp = b - c < 0 ? 40 + (c - b) : c - b;
		ans += tmp * 9;
		tmp = d - c < 0 ? 40 + (c - d) : c - d;
		ans += tmp * 9;
		printf("%d\n", ans);
	}
	return 0;
}
		
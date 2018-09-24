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
	int x, y;
	while (scanf("%d %d", &x, &y) == 2, (x || y)) {
		int ans;
		if (x == 1 || y == 1) ans = max(x, y);
		else if (x == 2 || y == 2) ans = min(max(x, y) % 4, 2) * 2 + (max(x, y) / 4) * 4;
		else ans = ((x * y + 1) / 2);
		printf("%d knights may be placed on a %d row %d column board.\n", ans, x, y);
	}
	return 0;
}
		
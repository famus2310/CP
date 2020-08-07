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

bool grid[15][15];
int a, b;

bool isBound(int x, int y) {
	return x > 0 && y > 0 && x <= a && y <= b;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(grid, 1, sizeof(grid));
		char c;
		int ans = 0;
		scanf(" %c %d %d", &c, &a, &b);
		if (c == 'r') {
			ans = min(a, b);
		} else if (c == 'k') {
			int sum = a + b;
			int mx = max(a, b);
			ans = mx * (sum - mx) / 2;
		} else if (c == 'K') {
			ans = ((a + 1)/ 2) * ((b + 1) / 2);
		} else 
			ans = min(a, b);
		printf("%d\n", ans);
	}
	return 0;
}
		
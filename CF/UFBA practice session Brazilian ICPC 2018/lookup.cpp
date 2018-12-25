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

map<pair<int, int>, bool> vis;
map<pair<int, int>, int> memo;
int n;

int dfs(int x, int y) {	
	if (memo[{x, y}]) return memo[{x, y}];
	if (x == 0 || y == 0) return memo[{x, y}] = 0;
	if (vis[{x, y}]) return memo[{x, y}] = -INF;
	vis[{x, y}] = 1;
	int a = dfs(x - min(x, y), y + min(x, y));
	int b = dfs(x + min(x, y), y - min(x, y));	
	if (a == -INF || b == -INF) return memo[{x, y}] = -INF;
	else return memo[{x, y}] = max(a, b) + 1;
}

int main() {
	for (int n = 1; n <= 100; n++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			for (int i = 0; i <= j; i++) {
				vis.clear();
				ans = ans + max(dfs(j - i, i), 0);
				// debug(ans);
			}
	//		debug(ans);
		}
		printf("%d = %d\n", n, ans);
	}
	return 0;
}
		
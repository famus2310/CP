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

vector<int> adjList[205];
int color[205];

enum {GRAY = 0, RED = 1, BLUE = 2};

bool dfs(int now, int lastColor) {
	color[now] = lastColor == RED ? BLUE : RED;
	// cout << now << " " << color[now] << endl;
	bool ans = 1;
	for (int it : adjList[now]) {
		if (color[it] == GRAY) ans &= dfs(it, color[now]);
		else if (color[it] == color[now]) return 0;
	}
	return ans;
}

int main() {
	int t;
	while (scanf("%d", &t), t != 0) {
		// SET(vis, 0);
		for (int i = 0; i < 205; i++)
			adjList[i].clear();
		SET(color, GRAY);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		bool res = dfs(0, RED);
		printf("%s\n", res ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}
	return 0;
}
		
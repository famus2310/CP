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

char grid[55][55];
int n, m;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool vis[55][55];

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

char bfs(int x, int y) {
	char now = 'A';
	vis[x][y] = 1;
	queue<pair<int, int> > q;
	q.push({x, y});
	char ans = 'A';
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		char cnow = grid[now.first][now.second];
		ans = max(ans, cnow);
		for (int i = 0; i < 8; i++) {
			int curx = now.first + dx[i];
			int cury = now.second + dy[i];
			if (!isBound(curx, cury) || grid[curx][cury] != cnow + 1 || vis[curx][cury])
				continue;
			vis[curx][cury] = 1;
			q.push({curx, cury});
		}
	}
	return ans;
}

int main() {
	int t = 0;
	while (scanf("%d %d", &n, &m), n || m) {
		SET(vis, 0);
		t++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &grid[i][j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'A') {
					char tmp = bfs(i, j);
					ans = max(ans, (int)(tmp - 'A' + 1));
				}
			}
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
		
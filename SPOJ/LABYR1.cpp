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

bool vis[1005][1005];
char grid[1005][1005];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
int len = 0;
int ans = 0;
int lastX, lastY;

bool isBound(int a, int b) {
	return a >= 0 && b >= 0 && a < n && b < m;
}

void dfs(int x, int y) {
	vis[x][y] = 1;
	len++;
	if (len > ans) {
		ans = len;
		lastY = y;
		lastX = x;
	}
	for (int i = 0; i < 4; i++) {
		int curx = x + dx[i];
		int cury = y + dy[i];
		if (!isBound(curx, cury) || grid[curx][cury] == '#' || vis[curx][cury]) continue;
		dfs(curx, cury);
	}
	len--;
	vis[x][y] = 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &grid[i][j]);
				vis[i][j] =  0;
			}
		}
		ans = 0;
		for (int i = 0; i < n && ans == 0; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] != '#') { 
					dfs(i, j);
					break;
				}
			}
		}
		dfs(lastX, lastY);
		printf("Maximum rope length is %d.\n", ans - 1);
	}
	return 0;
}
		
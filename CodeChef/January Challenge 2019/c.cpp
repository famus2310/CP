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

int n, m;
int grid[55][55];
bool vis[15];

int dx[] = {-2, -1, -1, 0, 0, 1, 1, 2};
int dy[] = {0, -1, 1, -2, 2, -1, 1, 0};

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(grid, 0);
		scanf("%d %d", &n, &m);
		int mx = 0;
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		SET(vis, 0);
		// 		for (int k = 0; k < 8; k++) {
		// 			int curx = i + dx[k];
		// 			int cury = j + dy[k];
		// 			if (!isBound(curx, cury)) continue;
		// 			if (grid[curx][cury] != 0)
		// 				vis[grid[curx][cury]] = 1;
		// 		}
		// 		for (int k = 1; k < 15; k++) {
		// 			if (!vis[k]) {
		// 				grid[i][j] = k;
		// 				mx = max(mx, k);
		// 				break;
		// 			}
		// 		}
		// 	}
		// }
		// if (mx > 4) {
			mx = 4;
			for (int i = 0; i < n; i++) {
				int now = i % 4 == 0 || i % 4 == 3 ? 0 : 2;
				for (int j = 0; j < m; j++) {
					grid[i][j] = (now + j) % 4 + 1;
				}
			}
		// }
		printf("%d\n", mx);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d%c", grid[i][j], j == m - 1 ? '\n' : ' ');
			}
		}
	}
	return 0;
}
		
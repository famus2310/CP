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

int grid[105][105];

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int n, m;

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
	int tc = 1;
	while (scanf("%d %d", &n, &m), n || m) {
		if (tc != 1) puts("");
		SET(grid, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (c == '*') 
					grid[i][j] = -1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == -1) continue;
				int mine = 0;
				for (int k = 0; k < 8; k++) {
					if (!isBound(i + dx[k], j + dy[k])) continue;
					int tmp_x = i + dx[k], tmp_y = j + dy[k];
					if (grid[tmp_x][tmp_y] == -1) mine++;
				}
				grid[i][j] = mine;
			}
		}

		printf("Field #%d:\n", tc++);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == -1) printf("*");
				else printf("%d", grid[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
		
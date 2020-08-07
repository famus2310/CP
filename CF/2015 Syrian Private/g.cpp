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

char grid[25][25];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf(" %c", &grid[i][j]);
		bool fnd = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'i') {
					bool fndp = 0;
					bool fnde = 0;
					for (int k = 0; k < 8; k++) {
						int curx = i + dx[k];
						int cury = j + dy[k];
						if (!isBound(curx, cury))
							continue;
						fndp |= grid[curx][cury] == 'p';
						fnde |= grid[curx][cury] == 'e';
					}
					if (fndp && fnde)
						fnd = 1;
				}
			}
		}
		if (fnd)
			puts("Cutie Pie!");
		else puts("Sorry Man");
	}
	return 0;
}
		
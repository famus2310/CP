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

int n, m;
char grid[1005][1005];
bool check[1005][1005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, pair<int, int> > > ans;

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &grid[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*') {
				bool flag = 1;
				for (int k = 0; k < 4; k++) {
					if (!isBound(i + dx[k], j + dy[k])) flag = 0;
					else if (grid[i + dx[k]][j + dy[k]] != '*') flag = 0;
				}
				if (!flag) continue;
				check[i][j] = 1;
				for (int k = 0; k < 4; k++) {
					check[i + dx[k]][j + dy[k]] = 1;
				}
				int ray = 1;
				while (flag) {
					ray++;
					for (int k = 0; k < 4; k++) {
						if (!isBound(i + dx[k] * ray, j + dy[k] * ray)) flag = 0;
						else if (grid[i + dx[k] * ray][j + dy[k] * ray] != '*') flag = 0;
					}
					if (flag) {
						for (int k = 0; k < 4; k++) {
							check[i + dx[k] * ray][j + dy[k] * ray] = 1;
						}
					}
				}
				ray--;
				ans.pb({i + 1, {j + 1, ray}});
			}
		}
	}
	bool pos = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*' && !check[i][j]) pos = 0;
		}
	}
	if (!pos) puts("-1");
	else {
		printf("%d\n", (int)ans.size());
		for (auto it : ans) {
			printf("%d %d %d\n", it.first, it.second.first, it.second.second);
		}
	}
	return 0;
}
		
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
char grid[305][305];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isBound(int x, int y) {
	return x >= 0 && y >=0 && x < n && y < m;
}

int bfs(int x, int y, int a, int b) {
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
	int vis[305][305];
	for (int i = 0; i < 305; i++)
		for (int j = 0; j < 304; j++)
			vis[i][j] = INF;
	q.push({0, {x, y}});
	while (!q.empty()) {
		int step = q.top().first;
		int xnow = q.top().second.first;
		int ynow = q.top().second.second; q.pop();
		if (vis[xnow][ynow] <= step || grid[xnow][ynow] == '#') continue;
		vis[xnow][ynow] = step;
		if (grid[xnow][ynow] == 'T') return step;
		for (int i = 0; i < 4; i++) {
			int tmpx = xnow + dx[i];
			int tmpy = ynow + dy[i];
			if (!isBound(tmpx, tmpy))
				continue;
			int tmpstep = grid[tmpx][tmpy] == '*' ? step + 1 : step;
			if (vis[tmpx][tmpy] <= tmpstep)
				continue;
			q.push({tmpstep, {tmpx, tmpy}});
 		}
 	}
 	return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int stx, sty, enx, eny;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'Y') {
					stx = i;
					sty = j;
				} else if (grid[i][j] == 'T') {
					enx = i;
					eny = j;
				}
			}
		}
		printf("Kasus #%d: %d\n", tc, bfs(stx, sty, enx, eny));
	}
	return 0;
}
		
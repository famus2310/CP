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

LL t;
LL n, m;
char grid[105][105];
LL xdest, ydest;
LL dx[] = {-1, 0, 1, 0};
LL dy[] = {0, 1, 0, -1};

struct node{
	LL cnt, x, y;
};

bool isValid(LL x, LL y) {
	return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 'X';
}

LL bfs(LL x, LL y) {
	queue<node> q;
	LL vis[105][105];
	memset(vis, 0, sizeof vis);
	LL tmp = 0;
	for (int i = 0; i < 4; i++) {
		if (!isValid(x + dx[i], y + dy[i])) continue;
		tmp++;
	}
	for (int i = 0; i < 4; i++) {
		if (!isValid(x + dx[i], y + dy[i])) continue;
		if (tmp > 1) q.push({1, x + dx[i], y + dy[i]});
		else q.push({0, x + dx[i], y + dy[i]});
	}
	vis[x][y] = 1;
	while (!q.empty()) {
		node now = q.front(); q.pop();
		tmp = 0;
		if (grid[now.x][now.y] == '*') return now.cnt;
		for (int i = 0; i < 4; i++) {
			if (!isValid(now.x + dx[i], now.y + dy[i])) continue;
			tmp++;
		}
		if (tmp > 2) now.cnt++;
		for (int i = 0; i < 4; i++) {
			if (!isValid(now.x + dx[i], now.y + dy[i])) continue;
			if (vis[now.x + dx[i]][now.y + dy[i]]) continue;
			vis[now.x + dx[i]][now.y + dy[i]] = 1;
			q.push({now.cnt, now.x + dx[i], now.y + dy[i]});
		}
	}
	return -1;
}

int main() {
	scanf("%lld", &t);
	while (t--) {
		LL xstart, ystart;
		scanf("%lld %lld", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				grid[i][j] = c;
				if (c == 'M') {
					xstart = i;
					ystart = j;
				}
			}
		}
		LL guess;
		scanf("%lld", &guess);
		printf("%s", bfs(xstart, ystart) == guess ? "Impressed\n" : "Oops!\n");
	}
	return 0;
}
		
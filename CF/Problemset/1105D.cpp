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

struct pt {
	int x, y;
};

int n, m;
char grid[1005][1005];
int occupied[1005][1005];
int players;
pt player[15];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ans[15];
int dist[15];
int limit;
queue<pair<int, pair<int, int> > > q;

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int player, int turn, int x, int y) {
	if (turn == 0 || limit == 0)
		return;
	for (int i = 0; i < 4; i++) {
		int curx = x + dx[i];
		int cury = y + dy[i];
		if (!isBound(curx, cury) || occupied[curx][cury] || grid[curx][cury] == '#')
			continue;
		occupied[curx][cury] = player;
		ans[player]++;
		limit--;
		turn--;
		debug(turn);
		dfs(player, turn, curx, cury);
		q.push({player, {curx, cury}});
	}
}

void bfs() {
	SET(occupied, 0);
	for (int i = 1; i <= players; i++) {
		ans[i] = 1;
		q.push({i, {player[i].x, player[i].y}});
		occupied[player[i].x][player[i].y] = i;
		limit--;
	}
	while (limit) {
		int now = q.front().first;;
		int xnow = q.front().second.first;
		int ynow = q.front().second.second;
		q.pop();
		debug(limit);
		dfs(now, dist[now], xnow, ynow);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &players);
	for (int i = 1; i <= players; i++)
		scanf("%d", dist + i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			scanf(" %c", &c);
			if (isdigit(c)) {
				player[c - '0'] = {i, j};
			}
			grid[i][j] = c;
		}
	}
	limit = n * m;
	bfs();
	for (int i = 1; i <= players; i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
		
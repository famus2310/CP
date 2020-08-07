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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int NMAX = 128;
const int N = NMAX * NMAX;

int dist[NMAX][NMAX];
bool notPrime[N];
int grid[NMAX][NMAX];
pair<int, int> pos[N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!notPrime[i]) {
			for (int j = i * i; j < N; j += i)
				notPrime[j] = 1;
		}
	}
}

void produce() {
	SET(grid, -1);
	int xnow = 0;
	int ynow = 0;
	int now = N;
	grid[xnow][ynow] = now;
	now--;
	while (now) {
		while (ynow + 1 < 128 && grid[xnow][ynow + 1] == -1) {
			ynow++;
			grid[xnow][ynow] = notPrime[now];
			pos[now] = {xnow, ynow};
			now--;
		}
		while (xnow + 1 < 128 && grid[xnow + 1][ynow] == -1) {
			xnow++;
			grid[xnow][ynow] = notPrime[now];
			pos[now] = {xnow, ynow};
			now--;
		}
		while (ynow - 1 >= 0 && grid[xnow][ynow - 1] == -1) {
			ynow--;
			grid[xnow][ynow] = notPrime[now];
			pos[now] = {xnow, ynow};
			now--;
		}
		while (xnow - 1 >= 0 && grid[xnow - 1][ynow] == -1) {
			xnow--;
			grid[xnow][ynow] = notPrime[now];
			pos[now] = {xnow, ynow};
			now--;
		}
	}
}

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < NMAX && y < NMAX;
}

int bfs(int src, int dst) {
	SET(dist, -1);
	queue<pair<int, int> > q;
	q.push({pos[src].first, pos[src].second});
	dist[pos[src].first][pos[src].second] = 0;
	while (!q.empty()) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		q.pop();
		if (xnow == pos[dst].first && ynow == pos[dst].second)
			return dist[xnow][ynow];
		for (int i = 0; i < 4; i++) {
			int curx = xnow + dx[i];
			int cury = ynow + dy[i];
			if (!isBound(curx, cury) || !grid[curx][cury] || dist[curx][cury] != -1)
				continue;
			dist[curx][cury] = dist[xnow][ynow] + 1;
			q.push({curx, cury});
		}
	}
	return -1;
}

int main() {
	sieve();
	produce();
	int x, y;
	int t = 1;
	while (scanf("%d %d", &x, &y) == 2) {
		int ans = bfs(x, y);
		printf("Case %d: ", t);
		if (ans == -1)
			puts("impossible");
		else printf("%d\n", ans);
		t++;
	}
	return 0;
}
		
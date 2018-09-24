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

const int NMAX = 1e5 + 5;

bool isValid(char r1, char c1, char r2, char c2) {
	return abs((int)r1 - (int)r2) % 2 ==  abs ((int)c2 - (int)c1) % 2;
}

bool isBound(char x, char y) {
	return x >= '1' && y >= 'A' && x <= '8' && y <= 'H';
}

int grid[256][256];
int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, -1, 1};

struct node{
	char x, y;
	string s;
};

void bfs(char ax, char ay, char bx, char by) {
	memset(grid, -1, sizeof(grid));
	queue<node> q;
	string tmp; tmp.pb(ay); tmp.pb(ax);
	q.push({ax, ay, tmp});
	grid[ax][ay] = 0;
	while (!q.empty()) {
		node now = q.front(); q.pop();
		if (grid[now.x][now.y] > 4) continue;
		if (now.x == bx && now.y == by) {
			cout << grid[now.x][now.y];
			for (int i = 0; i < now.s.size(); i++) cout << " " << now.s[i];
			cout << endl;
			return;
		}
		int distnow = grid[now.x][now.y];
		for (int i = 0; i < 4; i++) {
			char tmpx = (char)(now.x + dx[i]), tmpy = (char)(now.y + dy[i]);
			while (isBound(tmpx, tmpy)) {
				if (grid[tmpx][tmpy] == -1) {
					grid[tmpx][tmpy] = distnow + 1;
					string k = now.s; k.pb(tmpy); k.pb(tmpx);
					q.push({tmpx, tmpy, k});
				}
				tmpx += dx[i]; tmpy += dy[i];
			}
		}
	}
	cout << "Impossible" << endl;
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		char r1, c1, r2, c2;
		cin >> c1 >> r1 >> c2 >> r2;
		if (!isValid(r1, c1, r2, c2)) {
			cout << "Impossible" << endl;
			continue;
		}
		bfs(r1, c1, r2, c2);
	}
	return 0;
}
		
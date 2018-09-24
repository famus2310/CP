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

char grid[15][15];
int bkx, bky, wkx, wky;
bool bk = 0, wk = 0;
int dx[] = {1, 1, 0, 1, -1, -1, 0, -1};
int dy[] = {0, 1, 1, -1, 0, -1, -1, 1};
int kx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int ky[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool isBound(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void solvePawn(int x, int y, char c) {
	if (c == 'p') {
		if (isBound(x + 1, y + 1) && grid[x + 1][y + 1] == 'K') 
			wk = 1;
		else if (isBound(x + 1, y - 1) && grid[x + 1][y - 1] == 'K')
			wk = 1;
	} else {
		if (isBound(x - 1, y + 1) && grid[x - 1][y + 1] == 'k') 
			bk = 1;
		else if (isBound(x - 1, y - 1) && grid[x - 1][y - 1] == 'k')
			bk = 1;
	}
}

void solveRook(int x, int y, char c) {
	bool still = 1;
	int tmpx, tmpy;
	for (int i = 0; i < 8; i += 2) {
		still = 1;
		tmpx = x + dx[i], tmpy = y + dy[i];
		while (isBound(tmpx, tmpy) && still) {
			if (grid[tmpx][tmpy] == '.') {
				tmpx = tmpx + dx[i]; tmpy = tmpy + dy[i];
			} else {
				still = 0;
				if (grid[tmpx][tmpy] == 'k' && c == 'R') bk = 1;
				else if (grid[tmpx][tmpy] == 'K' && c == 'r') wk = 1;
			}
		}
	}
}

void solveQueen(int x, int y, char c) {
	bool still = 1;
	int tmpx, tmpy;
	for (int i = 0; i < 8; i++) {
		still = 1;
		tmpx = x + dx[i]; tmpy = y + dy[i];
		while (isBound(tmpx, tmpy) && still) {
			if (grid[tmpx][tmpy] == '.') {
				tmpx = tmpx + dx[i]; tmpy = tmpy + dy[i];
			} else {
				still = 0;
				if (grid[tmpx][tmpy] == 'k' && c == 'Q') bk = 1;
				else if (grid[tmpx][tmpy] == 'K' && c == 'q') wk = 1;
			}
		}
	}
}

void solveBishop(int x, int y, char c) {
	bool still = 1;
	int tmpx, tmpy;
	for (int i = 1; i < 8; i += 2) {
		still = 1;
		tmpx = x + dx[i]; tmpy = y + dy[i];
		while (isBound(tmpx, tmpy) && still) {
			if (grid[tmpx][tmpy] == '.') {
				tmpx = tmpx + dx[i]; tmpy = tmpy + dy[i];
			} else {
				still = 0;
				if (grid[tmpx][tmpy] == 'k' && c == 'B') bk = 1;
				else if (grid[tmpx][tmpy] == 'K' && c == 'b') wk = 1;
			}
		}
	}
}

void solveKnight(int x, int y, char c) {
	for (int i = 0; i < 8; i++) {
		if (isBound(x + kx[i], y + ky[i])) {
			if (grid[x + kx[i]][y + ky[i]] == 'k' && c == 'N') bk = 1;
			else if (grid[x + kx[i]][y + ky[i]] == 'K' && c == 'n') wk = 1;
		}
	}
}

void solveKing(int x, int y, char c) {
	for (int i = 0; i < 8; i++) {
		if (isBound(x + dx[i], y + dy[i])) {
			if (grid[x + dx[i]][y + dy[i]] == 'k' && c == 'K') bk = 1;
			else if (grid[x + dx[i]][y + dy[i]] == 'K' && c == 'k') wk = 1;
		}
	}
}

int main() {
	int tc = 1;
	while (scanf(" %c", &grid[0][0]) == 1) {
		bool read = grid[0][0] == '.' ? 0 : 1;
		wk = 0; bk = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i == 0 && j == 0) continue;
				scanf(" %c", &grid[i][j]);
				if (grid[i][j] != '.') read = 1;
				if (grid[i][j] == 'k') {
					bkx = i; bky = j;
				} else if (grid[i][j] == 'K') {
					bkx = i; bky = j;
				}
			}
		}
		if (!read) break;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char now = grid[i][j];
				if (now == 'p' || now == 'P') solvePawn(i, j, now);
				else if (now == 'r' || now == 'R') solveRook(i, j, now);
				else if (now == 'b' || now == 'B') solveBishop(i, j, now);
				else if (now == 'q' || now == 'Q') solveQueen(i, j, now);
				else if (now == 'k' || now == 'K') solveKing(i, j, now);
				else if (now == 'n' || now == 'N') solveKnight(i, j, now);
			}
		}
		if (bk) printf("Game #%d: black king is in check.\n", tc++);
		else if (wk) printf("Game #%d: white king is in check.\n", tc++);
		else printf("Game #%d: no king is in check.\n", tc++); 
	}
	return 0;
}
		
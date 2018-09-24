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

int n, h;
string s;
char grid[1005][1005];
int now = 0;
int colSize[1005];
int x, y;

void init() {
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++)
			grid[i][j] = '.';
	}
	memset(colSize, -1, sizeof colSize);
}

void walk() {
	while (now < n && x >= 0) {
		grid[x][y] = s[now];
		colSize[x] = max(colSize[x], y);
		x--;
		now++;
	}
	++x;
	++y;
	int cnt = 0;
	while (now < n && cnt < h / 2) {
		grid[x][y] = s[now];
		colSize[x] = max(colSize[x], y);
		now++;
		y++;
		cnt++;
	}
	--y;
	++x;
	cnt = 0;
	while (now < n && cnt < h / 2) {
		grid[x][y] = s[now];
		colSize[x] = max(colSize[x], y);
		now++;
		x++;
		cnt++;
	}
	--x;
	--y;
	cnt = 0;
	while (now < n && cnt < h / 2 - 1) {
		grid[x][y] = s[now];
		colSize[x] = max(colSize[x], y);
		now++;
		y--;
		cnt++;
	}
	++y;
	++x;
	cnt = 0;
	while (now < n && cnt < h / 2) {
		grid[x][y] = s[now];
		colSize[x] = max(colSize[x], y);
		now++;
		x++;
		y++;
		cnt++;
	}
	x--;
	if (now < n) {
		grid[x][y] = s[now];
		colSize[x] = max(colSize[x], y);
		now++;
		y++;
	}
}

int main() {
	scanf("%d %d", &n, &h);
	cin >> s;
	if (h == 1) {
		cout << s << endl;
		return 0;
	}
	init();
	x = h - 1;
	y = 0;
	while (now < n)
		walk();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= colSize[i]; j++) {
			if (grid[i][j] == '.') grid[i][j] = '#';
			printf("%c", grid[i][j]);
		}
		puts("");
	}
	return 0;
}
		
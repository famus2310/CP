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

int obj[105][105];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isBound(int x, int y) {
	return x < 105 && y < 105 && x > 0 && y > 0;
}

void solve(int x, int y, int z) {
	//0 kanan, 1 atas, 2 kiri, 3 bawah
	double now = 1;
	double eps = 1e-8;
	double ans = 0;
	while (now > eps) {
		if (!isBound(x, y)) break;
		if (obj[x][y] == 0) {
			now = now / 2.0;
			if (z == 1) z = 2;
			else if (z == 2) z = 1;
			else if (z == 3) z = 0;
			else z = 3;
		} else if (obj[x][y] == 1) {
			now = now / 2.0;
			if (z == 1) z = 0;
			else if (z == 0) z = 1;
			else if (z == 2) z = 3;
			else z = 2;
		} else if (obj[x][y] == 2) {
			ans = ans + now;
		}
		x += dx[z], y += dy[z];
	}
	cout << ans << endl;
}

int main() {
	SET(obj, -1);
	int n, c, t, q;
	scanf("%d %d %d %d", &n, &c, &t, &q);
	int shooterx = 1, shootery = 1;
	for (int i = 0; i < c; i++) {
		int x, y, s;
		scanf("%d %d %d", &x, &y, &s);
		obj[x][y] = s;
	}
	for (int i = 0; i < t; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		obj[x][y] = 2;
	}
	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			shooterx = x; shootery = y;
		} else if (type == 2) {
			int x, y;
			scanf("%d %d", &x, &y);
			obj[x][y] = (obj[x][y] + 1) % 2;
		} else if (type == 3) {
			int xi, yi, xj, yj;
			scanf("%d %d %d %d", &xi, &yi, &xj, &yj);
			obj[xj][yj] = 2;
			obj[xi][yi] = -1;
		} else {
			int z;
			scanf("%d", &z);
			solve(shooterx, shootery, z);
		}
	}
	return 0;
}
		
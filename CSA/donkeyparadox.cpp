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

double dist(int x1, int x2, int y1, int y2) {
	return (double) ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double manhattan(int x1, int x2, int y1, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (manhattan(i, ax, j, ay) == manhattan(i, bx, j, by)) cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
		
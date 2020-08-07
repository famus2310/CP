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

LL matrix[2005][2005];
LL col[2005];
LL row[2005];
LL n, m;

LL manhattan(LL xi, LL yi, LL xj, LL yj) {
	LL dx = xi - xj;
	LL dy = yi - yj;
	return abs(dx) + abs(dy);
}

int main() {
	LL total = 0;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lld", &matrix[i][j]);
			total += matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		row[i] = 0;
		for (int j = 0; j < m; j++) row[i] += matrix[i][j];
	}
	for (int i = 0; i < m; i++) {
		col[i] = 0;
		for (int j = 0; j < n; j++) col[i] += matrix[j][i];
	}
	LL now = -INF;
	LL distNow = INF;
	LL centerN = ceil((double)n / 2.0) - 1;
	LL centerM = ceil((double)m / 2.0) - 1;
	LL ansX, ansY;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			LL temp = total - row[i] - col[j] + matrix[i][j];
			LL distTemp = manhattan(i, j, centerN, centerM);
			if (temp > now) {
				ansX = i;
				ansY = j;
				now = temp;
				distNow = distTemp;
			}
			else if (temp == now) {
				if (distNow > distTemp) {
					ansX = i;
					ansY = j;
					distNow = distTemp;
				} else if (distNow == temp) {
					if (i < ansX) ansX = i;
					else if (i == ansX && j < ansY) ansY = j;
				}
			}
		}
	}
	printf("%lld\n%lld %lld\n", now, ansX + 1, ansY + 1);
	return 0;
}
		
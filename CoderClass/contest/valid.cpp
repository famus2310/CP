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



LL mx = -1;
LL dx[] = {0, 1, 0, -1};
LL dy[] = {1, 0, -1, 0};
bool pululu[105][105];
LL n, m;
bool vis[1005][1005];


bool isBound(LL x, LL y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

bool isPululu(LL x, LL y) {
	LL ret = 0;
	LL tmpx = x, tmpy =  y;
	while (isBound(tmpx + 1, tmpy)) {
		if (pululu[tmpx + 1][tmpy]) {
			ret++;
			break;
		} 
		tmpx = tmpx + 1;
	}
	tmpx = x, tmpy =  y;
	while (isBound(tmpx - 1, tmpy)) {
		if (pululu[tmpx - 1][tmpy]) {
			ret++;
			break;
		} 
		tmpx = tmpx - 1;
	}
	tmpx = x, tmpy =  y;
	while (isBound(tmpx, tmpy + 1)) {
		if (pululu[tmpx][tmpy + 1]) {
			ret++;
			break;
		} 
		tmpy = tmpy + 1;
	}
	tmpx = x, tmpy =  y;
	while (isBound(tmpx, tmpy - 1)) {
		if (pululu[tmpx][tmpy - 1]) {
			ret++;
			break;
		} 
		tmpy = tmpy - 1;
	}
	return ret > 2;
}



int main() {
	// scanf("%lld %lld", &n, &m);
	for (n = 1; n <= 5; n++) {
		for (m = 1; m <= 5; m++) {
			mx = 0;
			LL lim = pow(2.0, n * m);
			for (LL i = 0; i < lim; i++) {
				memset(pululu, false, sizeof(pululu));
				for (LL j = 0; j < m * n; j++) {
					if (i & (1 << j)) {
						pululu[j / m][j % m] = 1;
					}
				}
				bool flag = 1;
				for (LL k = 0; k < n && flag; k++) {
					for (LL j = 0; j < m && flag; j++) {
						if (pululu[k][j] && isPululu(k, j)) 
							flag = 0;
					}
				}
				if (flag) {
					LL now = __builtin_popcount(i);
					mx = max(now, mx);
				}
			}
			printf("%lld %lld = %lld\n", n, m, mx);
		}
	}
	return 0;
}
		
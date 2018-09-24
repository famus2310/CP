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

int device[25];
bool turned[25];
int n, m, c;

int main() {
	int seq = 1;
	while (scanf("%d %d %d", &n, &m, &c) == 3, (n || m || c)) {
		for (int i = 1; i <= n; i++)
			scanf("%d", device + i);
		memset(turned, 0, sizeof turned);
		int now = 0;
		bool blow = 0;
		int mx = 0;
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			if (turned[x]) {
				turned[x] = 0;
				now -= device[x];
			} else {
				turned[x] = 1;
				now += device[x];
			}
			if (now > c)
				blow = 1;
			// debug(now);
			mx = max(mx, now);
		}
		printf("Sequence %d\n", seq++);
		if (blow)
			puts("Fuse was blown.");
		else {
			puts("Fuse was not blown.");
			printf("Maximal power consumption was %d amperes.\n", mx);
		}
		puts("");
	}
	return 0;
}
		
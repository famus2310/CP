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

int r[3], g[3], b[3];
char s[2 * N];

int main() {
	SET(r, 0);
	SET(g, 0);
	SET(b, 0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", s + i);
		if (s[i] == 'R') {
			g[i % 3]++;
			b[i % 3]++;
		} else if (s[i] == 'G') {
			r[i % 3]++;
			b[i % 3]++;
		} else {
			r[i % 3]++;
			g[i % 3]++;
		}
	}
	int mx = INF;
	int idr, idg, idb;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				continue;
			for (int k = 0; k < 3; k++) {
				if (k == i || k == j)
					continue;
				if (r[i] + g[j] + b[k] < mx) {
					mx = r[i] + g[j] + b[k];
					idr = i;
					idg = j;
					idb = k;
				}
			}
		}
	}
	printf("%d\n", mx);
	for (int i = 0; i < n; i++) {
		int now = i % 3;
		if (now == idr)
			s[i] = 'R';
		else if (now == idg)
			s[i] = 'G';
		else s[i] = 'B';
		printf("%c", s[i]);
	}
	puts("");
	return 0;
}
		
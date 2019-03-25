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


int main() {
	int n;
	scanf("%d", &n);
	int mn = -1;
	int mx = MOD;
	for (int i = 0; i < n; i++) {
		// mx[i] = last[i] = -1;
		int a;
		scanf("%d", &a);
		for (int j = 0; j < a - 1; j++) {
			int now;
			scanf("%d", &now);
			// fi[i] = max(f[i], now);
			mn = max(mn, now);
		}
		int ls;
		scanf("%d", &ls);
		// se[i] = ls;
		mx = min(ls, mx);
	}
	if (mn >= mx)
		printf("-1\n");
	else printf("%d\n", mx);
	return 0;
}
		
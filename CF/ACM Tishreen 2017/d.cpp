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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int rel[25];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(rel, 0);
		int p, n;
		scanf("%d %d", &p, &n);
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			b--;
			rel[a] = rel[a] | (1 << b);
		}
		int ans = 0;
		for (int i = 1; i < (1 << p); i++) {
			int ret = (1 << p) - 1;
			for (int j = 0; j < p; j++) {
				if (i & (1 << j)) {
					ret = ret & rel[j];
				}
			}
			int tmp = __builtin_popcount(ret) + __builtin_popcount(i);
			ans = max(tmp, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
		
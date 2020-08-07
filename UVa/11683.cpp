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


int main() {
	int h, c;
	while (scanf("%d %d", &h, &c) == 2, (h || c)) {
		// memset(vis, 0, sizeof vis);
		int last;
		scanf("%d", &last);
		int ans = h - last;
		for (int i = 1; i < c; i++) {
			int a;
			scanf("%d", &a);
			if (last > a) {
				ans += (last - a);
			}
			last = a;
		}
		printf("%d\n", ans);
	}
	return 0;
}
		
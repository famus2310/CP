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
	int t, n;
	scanf("%d %d", &t, &n);
	while (t--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if ((a + b) % 2 != (c + d) % 2)
			puts("can't reach!");
		else {
			int moves = max(abs(a - c), abs(b - d));
			printf("%d\n", moves);
		}
	}
	return 0;
}
		
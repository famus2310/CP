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

void solve(LL x) {
	for (LL i = 1; i * (i + 1) / 2 < 2 * x; i++) {
		double a = (double)(x - i * (i + 1) / 2) / (double)(i + 1);
		if (a == 0) continue;
		if (a - (LL)a == 0) {
			printf("%lld = %lld", x, (LL)a);
			for (LL j = 1; j <= i; j++)
				printf(" + %lld", (LL)a + j);
			puts("");
			return;
		}
	}
	puts("IMPOSSIBLE");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL x;
		scanf("%lld", &x);
		solve(x);
	}
	return 0;
}
		
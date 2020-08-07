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

bool ex[N];

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	LL ans = 1LL;
	LL mult = 0;
	for (int i = 0; i < k; i++) {
		LL a;
		scanf("%lld", &a);
		if (a > 0) {
			ex[a] = 1;
			mult++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ex[i]) {
			mult--;
			continue;
		}
		ans = (ans * mult) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
		
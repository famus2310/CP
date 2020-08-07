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
const int MOD =  5000011;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL f[N], g[N];

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL n, k;
		scanf("%lld %lld", &n, &k);
		f[1] = g[1] = 1;
		for (int i = 2; i <= n; i++) {
			g[i] = (f[i - 1] + g[i - 1]) % MOD;
			f[i] = ((i - k > 0 ? g[i - k] : 1)) % MOD;
		}
		printf("%lld\n", (f[n] + g[n]) % MOD);
	}
	return 0;
}
		
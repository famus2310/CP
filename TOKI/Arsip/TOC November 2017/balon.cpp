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

LL comb[1005][1005];

void preprocess() {
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) {
			if (i == 0) comb[i][j] = 0;
			else if (j == 0 || j == i) comb[i][j] = 1;
			else comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
}

LL PowMod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) {
			ret = (ret * a) % MOD;
		}
		b = b / 2;
		a = (a * a) % MOD;
	}
	return ret;
}

int main() {
	preprocess();
	LL n;
	scanf("%lld", &n);
	LL ans = 0LL;
	for (LL i = 0; i <= n; i += 2) {
		ans = (ans + (comb[n][i] * PowMod(2, n - i)) % MOD) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
		
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

void mult(LL A[2][2], LL B[2][2]) {
	LL T[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			T[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				T[i][j] = (T[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
			}
		}
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			A[i][j] = T[i][j];
}

LL powmod(LL b) {
	LL A[2][2] = {{1, 1}, {1, 0}};
	LL ret[2][2] = {{1, 0}, {0, 1}};
	while (b) {
		if (b & 1) mult(ret, A);
		b = b / 2;
		mult(A, A);
	}
	return ret[0][0] % MOD;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, m;
		scanf("%lld %lld", &n, &m);
		LL ans1 = powmod(m + 1);
		LL ans2 = powmod(n);
		// cout << ans1 << endl;
		LL ans = (ans1 - ans2 + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
		
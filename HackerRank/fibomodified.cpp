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

void mult(LL A[3][3], LL B[3][3]) {
	LL ret[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ret[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				ret[i][j] += (A[i][k] * B[k][j]) % MOD;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A[i][j] = ret[i][j];
		}
	}
}

LL power(LL F[3][3], LL n) {
	LL M[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
	if (n == 1) {
		return ((4 * F[0][0]) % MOD + (2 * F[0][1]) % MOD + (1 * F[0][2]) % MOD) % MOD;
	}
	power(F, n / 2);
	mult(F, F);
	if (n & 1) mult(F, M);
	return ((4 * F[0][0]) % MOD + (2 * F[0][1]) % MOD + (1 * F[0][2]) % MOD) % MOD;
}

LL solve(LL n) {
	LL tmp[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
	if (n == 1) return 2;
	else if (n == 2) return 4;
	else return power(tmp, n - 2);
}

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL n;
		scanf("%lld", &n);
		printf("%lld\n", solve(n));
	}
	return 0;
}
		
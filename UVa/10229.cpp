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

LL M;

void mult(LL A[2][2], LL B[2][2]) {
	LL C[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			C[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				C[i][j] += ((A[i][k] % M) * (B[k][j] % M)) % M; 
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			A[i][j] = C[i][j];
		}
	}
}

LL power(LL A[2][2], LL n) {
	LL B[2][2] = {{1, 1}, {1, 0}};
	if (n == 1) return A[0][0] % M;
	power(A, n / 2);
	mult(A, A);
	if (n & 1) mult(A, B);
	return A[0][0] % M;
}

LL solve(LL n) {
	LL A[2][2] = {{1, 1}, {1, 0}};
	if (n < 2) return n % M;
	else return power(A, n - 1);
}

LL powmod(LL a, LL b) {
	LL ret = 1;
	while (b) {
		if (b & 1) ret = a * ret;
		b = b >> 1;
		a = a * a;
	}
	return ret;
}

int main() {
	LL a, b;
	while(scanf("%lld %lld", &a, &b) == 2){
		M = powmod(2, b);
		printf("%lld\n", solve(a));
	}
	return 0;
}

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

void mult(LL A[2][2], LL B[2][2]) {
	LL C[2][2] = {{0, 0}, {0, 0}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			C[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
			}
		}
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			A[i][j] = C[i][j];
}

void output(LL x[2][2]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cout << x[i][j] << " ";
		cout << endl;
	}
}

LL modex(LL b) {
	LL a[2][2] = {{1, 1}, {1, 0}};
	LL ret[2][2] = {{1, 0}, {0, 1}};
	while (b) {
		if (b & 1) mult(ret, a);
		b = b >> 1LL;
		mult(a, a);
		// output(ret);
	}
	return (ret[0][0] + ret[0][1]) % MOD;
}

int main() {
	fastio;
	LL t;
	cin >> t;
	while (t--) {
		LL n;
		cin >> n;
		cout << modex(n) << endl;
	}
	return 0;
}
		
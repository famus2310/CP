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

const int NMAX = 1e4 + 5;

LL fib[NMAX];

int main() {
	fib[0] = 1;
	fib[1] = 2;
 	for (int i = 2; i < NMAX; i++) {
 		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
 	}
 	int t;
 	cin >> t;
 	while (t--) {
 		int n;
 		cin >> n;
 		cout << fib[n] << endl;
 	}
	return 0;
}
		
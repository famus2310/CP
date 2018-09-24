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

void solve(LL n, char src, char dest, char aux) {
	if (n == 1) printf("%lld %c %c\n", n, src, dest);
	else {
		solve(n - 1, src, aux, dest);
		printf("%lld %c %c\n", n, src, dest);
		solve(n - 1, aux, dest, src);
	}
}

int main() {
	LL n;
	scanf("%lld", &n);
	solve(n, 'A', 'C', 'B');
	return 0;
}
		
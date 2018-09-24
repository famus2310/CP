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

LL n, t;

LL solve(LL a) {
	if (a == 0 || a == 1) return 0;
	if (a % 4 == 3) return 1	;
	if (a % 2 == 0) return 0;
	return solve(a / 4 + 1);
}

int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		printf("%s\n", solve(n) ? "ZiYES" : "HuseyNO");
	}
	return 0;
}
		
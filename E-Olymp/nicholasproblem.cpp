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

int solve(LL n, LL m) {
	if (n >= m) return 0;
	int now = 1;
	for (int i = 1; i <= n; i++) {
		now = (now * i) % m;
	} 
	return now;
}

int main() {
	LL n, m;
	scanf("%lld %lld", &n, &m);
	printf("%d\n", solve(n, m));
	return 0;
}
		
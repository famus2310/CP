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


int main() {
	LL a, b;
	scanf("%lld %lld", &a, &b);
	while (a > 0 && b > 0 && (2 * a <= b || 2 * b <= a)) {
		if (a > b) a %= (2 * b);
		else b %= (2 * a);
	}
	printf("%lld %lld\n", a, b);
	return 0;
}
		
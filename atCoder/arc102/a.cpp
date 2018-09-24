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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	LL ans = 0LL;
	for (LL i = k; i / 2 <= n; i += k) {
		// debug(i);
		LL a = i - 1;
		LL b = 1;
		if (a == 0) continue;
		LL c = a;
		cout << a << " " << b << " " << c << endl;
		if ((a + c) % k == 0 && (b + c) % k == 0 && (a + b) % k == 0) {
			if (a == b && b == c) ans += 1;
			else if (a == b || a == c) ans += 3;
			else if (a != b && b != c && a != c) ans += 6;
		}
		cout << a << " " << b << " " << c << endl;
		c = b;
		if ((a + c) % k == 0 && (b + c) % k == 0 && (a + b) % k == 0) {
			if (a == b && b == c) ans += 1;
			else if (a == b || a == c) ans += 3;
			else if (a != b && b != c && a != c) ans += 6;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
		
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

LL gcdExtended(LL a, LL b, LL *x, LL *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	LL x1, y1;
	LL g = gcdExtended(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return g;
}

int main() {
	fastio;
	LL a, b;
	while (cin >> a >> b) {
		LL x0, y0;
		LL d = gcdExtended(a, b, &x0, &y0);
		LL add = a / d;
		LL red = b / d;
		// cout << x0 << " " << y0 << endl;
		while (abs(x0) + abs(y0) > abs(x0 + add) + abs(y0 - red)) {
			// cout << x0 << " " << y0 << endl;
			x0 += add;
			y0 -= red;
		}
		while (abs(x0) + abs(y0) == abs(x0 - add) + abs(y0 + red)) {
			// cout << x0 << " " << y0 << endl;
			x0 -= add;
			y0 += red;
		}
		cout << x0 << " " << y0 << " " << d << endl;
	}
	return 0;
}
		
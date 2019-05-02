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
	LL n;
	while (cin >> n) {
		if (n == 0)
			break;
		LL x0, y0;
		LL n1, n2, c1, c2;
		cin >> c1 >> n1;
		cin >> c2 >> n2;
		LL g = gcdExtended(n1, n2, &x0, &y0);
		x0 = x0 * (n / g);
		y0 = y0 * (n / g);
		// cout << x0 << " " << y0 << endl;
		if (n % g != 0) {
			cout << "failed" << endl;
			continue;
		}
		LL add = n1 / g;
		LL red = n2 / g;
		while (x0 < 0) {
			x0 += red;
			y0 -= add;
		}
		// cout << x0 << " " << y0 << endl;
		while (y0 < 0) {
			x0 -= red;
			y0 += add;
		}
 		if (x0 < 0 || y0 < 0) {
			cout << "failed" << endl;
			continue;
		} else {
			if (c1 < c2) {
				while (y0 - add >= 0) {
					y0 -= add;
					x0 += red;
				}
			} else {
				while (x0 - red >= 0) {
					x0 -= red;
					y0 += add;
				}
			}
			cout << x0 << " " << y0 << endl;
		}
	}
	return 0;
}

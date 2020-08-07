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

int main() {
	fastio;
	LL a, b, c;
	cin >> a >> b >> c;
	LL mult = min(a / 3, min(b / 2, c / 2));
	LL ans = 7 * mult;
	a -= mult * 3;
	b -= mult * 2;
	c -= mult * 2;
	if (a == 0) {
		if (b == 0) {
			if (c != 0) 
				ans++;
		} else {
			if (c != 0)
				ans += 2;
			else ans++;
		}
	} else if (a == 1) {
		if (b == 0) {
			if (c == 0) {
				ans++;
			} else if (c == 1) {
				ans += 2;
			} else {
				ans += 3;
			}
		} else if (b == 1) {
			if (c == 0) {
				ans += 2;
			} else if (c == 1) {
				ans += 3;
			} else {
				ans += 4;
			}
		} else {
			if (c == 0) {
				ans += 2;
			} else if (c == 1) {
				ans += 3;
			} else {
				ans += 5;
			}
		}
	} else if (a == 2) {
		if (b == 0) {
			if (c == 0) {
				ans += 2;
			} else if (c == 1) {
				ans += 2;
			} else {
				ans += 3;
			}
		} else if (b == 1) {
			if (c == 0) {
				ans += 3;
			} else if (c == 1) {
				ans += 4;
			} else {
				ans += 5;
			}
		} else {
			if (c == 0) {
				ans += 4;
			} else if (c == 1) {
				ans += 5;
			} else {
				ans += 6;
			}
		}
	} else {
		if (b == 0) {
			if (c == 0) {
				ans += 2;
			} else if (c == 1) {
				ans += 2;
			} else {
				ans += 3;
			}
		} else if (b == 1) {
			if (c == 0) {
				ans += 3;
			} else if (c == 1) {
				ans += 5;
			} else {
				ans += 6;
			}
		} else {
			if (c == 0) {
				ans += 4;
			} else if (c == 1) {
				ans += 6;
			} else ans += 7;
		}
	}
	cout << ans << endl;
	return 0;
}
		
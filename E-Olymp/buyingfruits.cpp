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
	LL n, m, a, b, c;
	cin >> m >> n >> a >> b >> c;
	for (LL x = 1; x <= n; x++) {
		LL r = n - x;
		LL s = m - a * x;
		if (r <= 0 || s <= 0)
			break;
		if (b == c) {
			if (s % b != 0)
				continue;
			if (s / b != r)
				continue;
			if (r == 1)
				continue;
			cout << x << " " << 1 << " " << r - 1 << endl;
			return 0;
		}
		LL y = c * r - s;
		LL z = b * r - s;
		LL divisor = c - b;
		if (y % divisor != 0 || z % divisor != 0)
			continue;
		y /= divisor;
		z /= -divisor;
		if (y <= 0 || z <= 0)
			continue;
		cout << x << " " << y << " " << z << endl;
		return 0;
	}
	cout << "NO SOLUTION" << endl;
	return 0;
}
		
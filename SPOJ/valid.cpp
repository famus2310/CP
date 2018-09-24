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
	int n;
	cin >> n;
	for (int a = 0; a <= n; a++) {
		for (int b = 0; b <= n; b++) {
			// if (b == a) continue;
			for (int c = 0; c <= n; c++) {
				// if (c == a || c == b) continue;
				for (int d = 0; d <= n; d++) {
					// if (d == a || d == b || d == c) continue;
					// cout << a << b << c << d << endl;
					if (a * b + c + d == 3 &&
						b * c + a + d == 5 &&
						c * d + a + b == 2 &&
						a * d + b + c == 6) cout << a << " " << b << " " << c << " " << d << endl;
				}
			}
		}
	}
	return 0;
}
		
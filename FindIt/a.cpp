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
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, a, b;
		scanf("%lld %lld %lld", &n, &a, &b);
		LL sum = a + b;
		LL diag;
		if (sum % 2 == 0)
			sum++;
		if (sum <= n + 2) {
			diag = ((sum - 2)* (sum - 1)) / 2 + 1;
		}
		else {
			LL y = n;
			LL x = sum - n - 1;
			diag = (n) * (n - 1) / 2 + (y * x - x * (x - 1) / 2) + 1;
		}
		LL nowx = max(1LL, a + b - n);
		LL nowy = a + b - nowx;
		if ((a + b) % 2 == 0) {
			diag--;
		}
		// cout << diag << endl;
		// cout << nowx << " " << nowy << endl;
		int red = (a + b) & 1 ? 1 : -1;
		while (nowx != a && nowy != b) {
			diag += red;
			nowx++;
			nowy--;
		}
		cout << diag << endl;
	}
	return 0;
}
		
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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int main() {
	LL t;
	cin >> t;
	while (t--) {
		LL n;
		cin >> n;
		LL ret = (4 + (6 * (n - 1)) % MOD + (2 * ((n - 2) * (n - 1)) %  MOD) % MOD) % MOD;
		LL a = n - 3;
		LL b = n - 1;
		LL c = n - 2;
		if (a % 3 == 0) a /= 3;
		else if (b % 3 == 0) b /= 3;
		else if (c % 3 == 0) c /= 3;
		if (a % 2 == 0) a /= 2;
		else if (b % 2 == 0) b /= 2;
		else c /= 2;
		ret = (ret + (((a * b) % MOD) * c) % MOD) % MOD;
		cout << ret << endl;
	}
	return 0;
}
		
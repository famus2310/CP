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

LL n, m, x;

int main() {
	fastio;
	cin >> n >> m >> x;
	LL ans = 0LL;
	for (int i = 0; i < n * m; i++) {
		LL a;
		cin >> a;
		if (__gcd(a, x) != 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
		
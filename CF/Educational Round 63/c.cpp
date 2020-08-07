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

LL n, m;
vector<LL> p;

int main() {
	fastio;
	cin >> n >> m;
	LL st;
	cin >> st;
	LL g = 0;
	LL last = st;
	for (int i = 1; i < n; i++) {
		LL a;
		cin >> a;
		LL diff = a - last;
		g = __gcd(g, diff);
		last = a;
	}
	for (int i = 0; i < m; i++) {
		LL x;
		cin >> x;
		p.pb(x);
	}
	// cout << g << endl;
	for (int i = 0; i < m; i++) {
		if (g % p[i] == 0) {
			cout << "YES" << endl;
			cout << st << " " << i + 1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
		
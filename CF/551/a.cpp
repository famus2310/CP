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
	int n, t;
	cin >> n >> t;
	int mn = INF;
	int id = -1;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		int x = (t - a) / b + ((t - a) % b != 0 && (t - a) > 0);
		x = max(x, 0);
		// cout << x << endl;
		// cout << a + b * x - t << endl;
		if (a + b * x  - t < mn) {
			mn = a + b * x - t;
			id = i;
		}
	}
	cout << id << endl;
	return 0;
}
		
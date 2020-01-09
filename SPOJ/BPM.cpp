#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

int main() {
	NeedForSpeed;
	ll t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ll n;
		cin >> n;
		ll ans;
		if (n & 1) {
			if ((n / 2) & 1) {
				ans = 0;
			} else ans = 1;
		} else {
			if ((n / 2) & 1) {
				ans = 1;
			} else ans = 0;
		}
		cout << "Case " << tc << ": " << ans << endl;
	}
	return 0;
}
		
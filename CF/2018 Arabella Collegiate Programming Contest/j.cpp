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

ll solve(ll n) {
	if (n == 0 || n == 1)
		return 0;
	if (n & 1)
		return solve(n / 2) * 2;
	return solve(n / 2) + n / 2;
}

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
		
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
	LL capacity[5];
	LL n;
	cin >> n;
	LL mn = INF64;
	for (int i = 0; i < 5; i++) {
		LL a;
		cin >> a;
		mn = min(mn, a);
	}
	cout << n / mn + 4 + (n % mn != 0) << endl;
	return 0;
}
		
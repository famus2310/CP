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

const int N = 1e7 + 5;

LL BIT[N];

void upd(LL x) {
	for(; x < N; x += (x & -x)) 
		BIT[x]++;
}

LL getSum(LL x) {
	LL ret = 0LL;
	for (; x > 0; x -= (x & -x))
		ret = ret + BIT[x];
	return ret;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		SET(BIT, 0);
		LL n;
		cin >> n;
		LL ans = 0LL;
		for (int i = 0; i < n; i++) {
			LL x;
			cin >> x;
			ans = ans + getSum(N - 1) - getSum(x);
			upd(x);
		}
		cout << ans << endl;
	}
	return 0;
}
		
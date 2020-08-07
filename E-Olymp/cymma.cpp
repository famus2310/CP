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

vector<pair<LL, LL> > ans;

void solve(LL x) {
	for (LL i = 0; i * (i + 1) / 2 <= 2 * x; i++) {
		double a = (double)(x - i * (i + 1) / 2) / (double)(i + 1);
		if (a <= 0) continue;
		if (a - (LL)a == 0) {
			ans.pb({a, a + i});
		}
	}
	if (ans.empty())
		puts("IMPOSSIBLE");
	else {
		sort(all(ans));
		printf("%d\n", ans.size());
		for (auto it : ans) {
			printf("%lld %lld\n", it.first, it.second);
		}
	}
}

int main() {
	LL x;
	scanf("%lld", &x);
	solve(x);
	return 0;
}
		
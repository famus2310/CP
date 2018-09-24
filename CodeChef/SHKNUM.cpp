#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

vector<LL> power_two;
map<LL, bool> vis;

void precompute() {
	for (int i = 0; i <= 32; i++) {
		for (int j = 0; j <= 32; j++) {
			if (i == j) continue;
			LL a = 1LL, b = 1LL;
			LL now = (a << i) + (b << j);
			if (vis[now]) continue;
			vis[now] = 1;
			power_two.pb(now);
		}
	}
	sort(all(power_two));
}

int main() {
	precompute();
	int t;
	scanf("%d", &t);
	while (t--) {
		LL a;
		scanf("%lld", &a);
		int up = lower_bound(all(power_two), a) - power_two.begin();
		int down = up - 1;
		if (down < 0)
			down  = up;
		LL ans = min(abs(power_two[down] - a), abs(power_two[up] - a));
		printf("%lld\n", ans);
 	}
	return 0;
}
		
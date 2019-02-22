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

vector<pair<LL, LL > > factor;
LL cnt[N];

void factorize(LL x) {
	LL cnt = 0;
	while (x % 2 == 0) {
		cnt++;
		x /= 2;
	}
	if (cnt > 0)
		factor.pb({2, cnt});
	LL lim = x;
	for (LL i = 3; i * i <= lim; i += 2) {
		cnt = 0;
		while (x % i == 0) {
			cnt++;
			x /= i;
		}
		if (cnt > 0)
			factor.pb({i, cnt});
	}
	if (x > 2)
		factor.pb({x, 1});
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(cnt, 0);
		factor.clear();
		LL x, n;
		scanf("%lld %lld", &x, &n);
		factorize(x);
		for (int i = 0; i < n; i++) {
			LL a;
			scanf("%lld", &a);
			for (int j = 0; j < factor.size(); j++) {
				LL div = 1;
				while (a / factor[j].first >= div) {
					div *= factor[j].first;
					cnt[j] += a / div;
				}
			}
		}
		LL ans = INF64;
		for (int i = 0; i < factor.size(); i++) {
			// debug(factor[i].second);
			ans = min(ans, cnt[i] / factor[i].second);
		}
 		printf("%lld\n", ans);
	}
	return 0;
}
		
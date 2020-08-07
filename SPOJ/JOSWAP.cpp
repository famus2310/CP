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

LL cnt[N];

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL total = 0LL;
		SET(cnt, 0LL);
		LL n;
		bool dob = 0;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) {
			LL a;
			scanf("%lld", &a);
			cnt[a]++;
			total ++;
			if (cnt[a] > 1) dob = 1;
		}
		LL ans = dob ? 1LL : 0LL;
		for (int i = 1; i < N && total; i++) {
			if (cnt[i] > 0) {
				ans = ans + cnt[i] * (total - cnt[i]);
				total -= cnt[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

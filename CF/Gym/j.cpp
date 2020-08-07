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

const int N = 1e4 + 5;

LL cnt[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			cnt[a]++;
		}
		LL ans = 0LL;
		for (int i = 1; i < N - 2; i++) {
			ans = max(ans, cnt[i] + cnt[i - 1] + cnt[i + 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		
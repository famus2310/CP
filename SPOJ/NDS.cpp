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

const int N = 1e6 + 5;

LL BIT[N];
LL arr[N];
LL tail[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL zero = 0;
		SET(BIT, 0);
		SET(tail, 0);
		LL n;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", arr + i);
		LL k;
		scanf("%lld", &k);
		if (n == 0) {
			puts("-1");
			continue;
		}
		LL ans = INF;
		tail[0] = arr[0];
		if (k == 1)
			ans = min(ans, arr[0]);
		int len = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i] > tail[len - 1]) { 
				tail[len] = arr[i];
				if (len + 1 >= k)
					ans = min(ans, arr[i]);
				len++;
			} else {
				LL ub = lower_bound(tail, tail + len, arr[i]) - tail;
				// debug(ub);
				if (tail[ub] == arr[i])
					continue;
				tail[ub] = arr[i];
				if (ub + 1 >= k)
					ans = min(ans, arr[i]);
			}
		}
		if (ans == INF)
			puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}
		
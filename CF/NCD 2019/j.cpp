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

LL arr[N];
LL diff[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(diff, 0);
		LL n, m;
		scanf("%lld %lld", &n, &m);
		for (int i = 0; i < m; i++) {
			LL a;
			scanf("%lld", &a);
			a--;
			arr[i] = a;
		}
		for (int i = 0; i < m; i++) {
			LL a;
			scanf("%lld", &a);
			if (a == 0) {
				diff[arr[i]]++;
				diff[arr[i] + 1]--;
			} else if (a > 0) {
				diff[arr[i]]++;
				if (arr[i] + a + 1 < n) {
					diff[arr[i] + a + 1]--;
				} else {
					diff[0]++;
					diff[arr[i] + a + 1 - n]--;
				}
			} else {
				diff[arr[i] + 1]--;
				if (arr[i] + a >= 0)
					diff[arr[i] + a]++;
				else {
					diff[0]++;
					diff[arr[i] + a + n]++;
				}
			}
		}
		LL ans;
		LL mx = 0;
		LL now = 0LL;
		for (int i = 0; i < n; i++) {
			now = now + diff[i];
			// debug(now);	
			if (now > mx) {
				mx = now;
				ans = i + 1;
			}
		}
		printf("%lld %lld\n", ans, mx);

	}
	return 0;
}
		
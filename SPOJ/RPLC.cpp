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

LL arr[N];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL n;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", arr + i);
		}
		LL now = 1LL;
		for (int i = n - 1; i >= 0; i--) {
			now -= arr[i];
			now = max(now, 1LL);
		}
		printf("Scenario #%d: %lld\n", tc, now);
	}
	return 0;
}
		
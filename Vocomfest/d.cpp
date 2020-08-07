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
LL two[N];

LL solve(LL x) {
	LL ret = 0LL;
	while (x % 2 == 0) {
		ret++;
		x /= 2;
	}
	return ret;
}

int main() {
	LL n;
	scanf("%lld", &n);
	LL lasttwo = -1;
	LL lastone1 = -1;
	LL lastone2 = -1;
	for (LL i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		two[i] = solve(a);
	}
	LL ans = 0LL;
	for (LL i = 1; i <= n; i++) {
		// debug(two[i]);
		// cout << ans << endl;
		if (two[i] == 0) {
			if (lasttwo == -1 && lastone2 == -1)
				continue;
			ans = ans + max(lasttwo, lastone2);
		} else if (two[i] >= 2) {
			lasttwo = i;
			ans = ans + i;
		} else if (two[i] == 1) {
			if (lastone1 == -1) {
				lastone1 = i;
				if (lasttwo != -1)
					ans = ans + lasttwo;
			} else {
				lastone2 = lastone1;
				lastone1 = i;
				ans = ans + max(lasttwo, lastone2);
			} 
		}
	}
	printf("%lld\n", ans);
	return 0;
}
		
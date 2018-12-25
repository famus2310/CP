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

LL arr[1005];
LL n;

bool check(LL x) {
	for (int i = 0; i < n; i++) {
		x = x + arr[i];
		if (x <= 0) return false;
	}
	return true;
}

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (LL i = 0; i < n; i++)
			scanf("%lld", arr + i);
		LL lo = 0;
		LL hi = (LL)1e10 + 5;
		while (hi - lo > 1) {
			LL mid = lo + (hi - lo) / 2;
			if (check(mid)) {
				hi = mid;
			} else lo = mid + 1;
		}
		if (hi < lo) swap(hi, lo);
		if (check(lo))
			printf("%lld\n", lo);
		else printf("%lld\n", hi);
	}
	return 0;
}
		
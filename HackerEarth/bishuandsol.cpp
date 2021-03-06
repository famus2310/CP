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

LL arr[10005];
LL prefix[10005];

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", arr + i);
	sort(arr + 1, arr + n + 1);
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}
	LL q;
	scanf("%lld", &q);
	while (q--) {
		LL x;
		scanf("%lld", &x);
		LL ub = upper_bound(arr + 1, arr + n + 1, x) - arr;
		ub--;
		printf("%lld %lld\n", ub, prefix[ub]);
	}
	return 0;
}
		
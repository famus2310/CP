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

LL rem[105];

int main() {
	SET(rem, 0);
	LL n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		rem[a % k]++;
	}
	LL ret = 0LL;
	for (LL i = 1; i < (k + 1) / 2; i++) {
		ret = ret + max(rem[i], rem[k - i]);
	}
	ret = ret + (rem[0] > 0 ? 1 : 0);
	if (k % 2 == 0)
		ret = ret + (rem[k / 2] > 0 ? 1 : 0);
	printf("%lld\n", ret);
	return 0;
}
		
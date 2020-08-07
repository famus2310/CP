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

const int N = 1e5 + 5;

LL idx[N], BITree[N], arr[N], last[N];

void upd(LL x, LL val) {
	for (; x < N; x += x & (-x))
		BITree[x] += val;
} 

LL getSum(LL x) {
	LL ret = 0LL;
	for (; x > 0; x -= x & (-x))
		ret += BITree[x];
	return ret;
}

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		memset(idx, 0, sizeof idx);
		memset(BITree, 0, sizeof BITree);
		BITree[0] = 0LL;
		LL n;
		scanf("%lld", &n);
		for (LL i = 0; i < n; i++) {
			LL a;
			scanf("%lld", &a);
			arr[i + 1] = a;
			idx[a] = i + 1;
		}
		LL ans = 0LL;
		for (LL i = 0; i < n; i++) {
			LL a;
			scanf("%lld", &a);
			ans += getSum(n + 1) - getSum(idx[a]);
			// debug(getSum(n)- getSum(idx[a]));
			// debug(ans);
			upd(idx[a], 1LL);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		
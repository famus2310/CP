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

int BIT[N];
LL arr[N];
LL add[N];

int main() {
	LL sum = 0LL;
	SET(BIT, 0);
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", arr + i);
	}
	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int idx;
			LL x;
			scanf("%d %lld", &idx, &x);
			arr[idx] = x;
			add[idx] = -sum;
		} else if (type == 2) {
			LL y;
			scanf("%lld", &y);
			sum += y;
		} else {
			int idx;		
			scanf("%d", &idx);
			LL ans = arr[idx] + add[idx] + sum;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
		
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

LL arr[N];
LL dimension[10];
LL dim1[10];
LL dim2[10];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int d;
		scanf("%d", &d);
		LL sz = 1LL;
		for (int i = 0; i < d; i++) {
			scanf("%lld", dimension + i);
			sz *= dimension[i];
		}
		for (int i = 0; i < sz; i++)
			scanf("%lld", arr + i);
		int q;
		scanf("%d", &q);
		while (q--) {
			for (int i = 0; i < d; i++) {
				scanf("%lld", dim1 + i);
				dim1[i]--;
			}
			for (int i = 0; i < d; i++) {
				scanf("%lld", dim2 + i);
				dim2[i]--;
			}
			LL curdim = 1LL;
			LL ans = 0LL;
			for (int i = 0; i < sz; i++) {
				bool err = 0;
				curdim = 1;
				for (int j = d - 1; j >= 0; j--) {
					LL now = (i / curdim) % dimension[j];
					// cout << now << " " << arr[i] << " ";
					if (dim1[j] > now || now > dim2[j]) {
						err = 1;
						// break;
					}
					curdim *= dimension[j];
				}
				// puts("");
				// debug(ans);
				if (!err)
					ans += arr[i];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
		
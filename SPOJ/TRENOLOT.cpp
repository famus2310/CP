#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
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
LL arr[55];
vector<LL> a[55], b[55];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 55; i++) {
			a[i].clear();
			b[i].clear();
		}
		LL n, k;
		scanf("%llu %llu", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%llu", arr + i);
		}
		LL mid = n / 2;
		LL mid2 = n - mid;
		for (LL i = 0; i < (1ULL << mid); i++) {
			LL tmp = 0LL;
			int take = 0;
			for (LL j = 0; j < mid; j++) {
				if (i & (1ULL << j)) {
					tmp = tmp + arr[j];
					take++;
				}
			}
			a[take].pb(tmp);
		}
		for (LL i = 0; i < (1ULL << mid2); i++) {
			LL tmp = 0LL;
			int take = 0;
			for (LL j = 0; j < mid2; j++) {
				if (i & (1ULL << j)) {
					tmp = tmp + arr[j + mid];
					take++;
				}
			}
			b[take].pb(tmp);
		}
		for (int i = 0; i <= k; i++) {
			sort(all(a[i]));
			sort(all(b[i]));
			// cout << "take "<< i << " : " << endl;
			// for (auto it : a[i]) {
			// 	cout<< it << " ";
			// }
			// cout << endl;
			// for (auto it : b[i])
			// 	cout << it << " ";
			// cout << endl;
		}
		LL x, y;
		scanf("%llu %llu", &x, &y);
		x--;
		LL ans1 = 0;
		LL ans2 = 0;
		for (int take = 0; take <= k; take++) {
			for (int i = 0; i < a[take].size(); i++) {
				LL rg = x - a[take][i];
				LL rg2 = y - a[take][i];
				int lb = upper_bound(all(b[k - take]), rg) - b[k - take].begin();
				int lb2 = upper_bound(all(b[k - take]), rg2) - b[k - take].begin();
				if (lb != 0 && x >= a[take][i])
					ans1 = ans1 + lb;
				if (lb2 != 0 && y >= a[take][i])
					ans2 = ans2 + lb2;
				// cout << "ambil k: " << take << endl;
				// debug(rg);
				// debug(rg2);
				// debug(lb);
				// debug(lb2);
				// debug(" ");
			}
		}
		printf("%llu\n", ans2 - ans1);
	}
	return 0;
}
		
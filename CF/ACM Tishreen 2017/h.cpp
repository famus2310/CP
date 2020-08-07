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

vector<int> v;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		v.clear();
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			vector<int> tmp;
			for (int j = 0; j < 3; j++) {
				int a;
				scanf("%d", &a);
				tmp.pb(a);
			}
			sort(all(tmp));
			v.pb(tmp[0]);
			v.pb(tmp[1]);
		}
		sort(all(v));
		LL ans = 0LL;
		for (int i = 0; i < k; i++)
			ans = ans + v[i];
		printf("%lld\n", ans);
	}
	return 0;
}
		
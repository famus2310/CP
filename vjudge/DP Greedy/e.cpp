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

vector<LL> house;

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	bool last = 0;
	bool applied = 0;
	int range = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		house.pb(a);
	}
	sort(all(house));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		// debug(i);
		ans++;
		int lb = upper_bound(all(house), house[i] + k) - house.begin();
		lb--;
		lb = upper_bound(all(house), house[lb] + k) - house.begin();
		// cout << "lb" << lb << endl;
		i = lb - 1;
	}
	printf("%d\n", ans);
	return 0;
}

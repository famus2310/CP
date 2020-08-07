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

map<double, bool> vis;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vis.clear();
		LL n, k;
		scanf("%lld %lld", &n, &k);
		if (k >= n)
			puts("YES");
		else if (n % k == 0 && (n / k) % 4 == 2) {
			puts("NO");
		} else puts("YES");
	}
	return 0;
}
	//6 - > 10 -> 4 - > 8 - > 2 - > 6 - > 0 - > 4 - > 10 - > 2 - > 8 - > 0 -> 6
//6 -> 7 - > 1 - > 2 - > 8
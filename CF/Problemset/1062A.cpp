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


int main() {
	int n;
	scanf("%d", &n);
	int last = 0;
	int now = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a != now + 1) {
			ans = max(ans, now - last - 1);
			now = a;
			last = a;
		} else {
			now = a;
		}
	}
	if (now == 1000)
		ans = max(ans, 1000 - last);
	else ans = max(ans, now - last - 1);
	printf("%d\n", ans);
	return 0;
}
		
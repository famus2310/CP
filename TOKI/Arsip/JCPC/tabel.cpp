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

int prefix[N];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (i == 1) prefix[i] = a;
		else prefix[i] = prefix[i - 1] ^ a;
	}
	while (q--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int l = max(a, b);
		int r = min(c, d);
		if (r < l) puts("0");
		// cout << prefix[r] << " " << prefix[l - 1] << endl;
		else printf("%d\n", prefix[r] ^ prefix[l - 1]);
	}
	return 0;
}
		
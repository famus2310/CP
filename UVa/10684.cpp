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
	while (scanf("%d", &n), n != 0) {
		int mxnow = 0;
		int last = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			last = max(last + a, 0);
			// debug(last);
			mxnow = max(last, mxnow);
		}
		if (mxnow == 0) puts("Losing streak.");
		else printf("The maximum winning streak is %d.\n", mxnow);
	}
	return 0;
}
		
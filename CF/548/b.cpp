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

LL arr[2 * N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	LL ans = arr[n - 1];
	LL mxnow = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		LL a = arr[i];
		if (a < mxnow) {
			mxnow = a;
		} else if (a == mxnow)
			mxnow = a - 1;
		else if (a > mxnow)
			mxnow = mxnow - 1;
		ans = ans + max(mxnow, 0LL);
	}
	printf("%lld\n", ans);
	return 0;
}
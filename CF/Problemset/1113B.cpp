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

int rem[105];

int main() {
	SET(rem, 0);
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		rem[a % k]++;
	}
	int ans = (rem[0] / 2) * 2;
	// debug(ans);
	for (int i = 1; i < (k + 1) / 2; i++) {
		ans += min(rem[i], rem[k - i]) * 2;
	}
	if (k % 2 == 0) {
		ans += (rem[k / 2] / 2) * 2;
	}
	printf("%d\n", ans);
	return 0;
}
		
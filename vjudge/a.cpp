#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL m, n1, n2;
LL arr[205];

int main() {
	while (scanf("%lld %lld %lld", &m, &n1, &n2) == 3 && m != 0 && n1 != 0 && n2 != 0) {
		LL ans = 0;
		LL mx = 0;
		for (int i = 0; i < m; i++) scanf("%lld", arr + i);
		for (int i = 0; i < m; i++) {
			if (i < n1 || i > n2) continue;
			if (arr[i - 1] - arr[i] >= mx) {
				mx = arr[i - 1] - arr[i];
				ans = i;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		
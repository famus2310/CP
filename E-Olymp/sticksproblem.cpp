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

int arr[N];

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		int ans = 0;
		int lo = 0;
		int hi = 0;
		int lasthi = INF;
		int lastlo = 0;
		while (hi < n) {
			int a;
			scanf("%d", &a);
			hi++;
			if (a <= lasthi || a == lastlo) {
				lastlo = a;
				lo = hi;
			}
			lasthi = a;
			ans = max(ans, hi - lo);
		}
		printf("%d\n", ans == 0 ? -1 : ans);
	}
	return 0;
}
		
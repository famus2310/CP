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


int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int n;
		scanf("%d", &n);
		int hi = 0, lo = 0;
		int now;
		scanf("%d", &now);
		for (int i = 1; i < n; i++) {
			int a;
			scanf("%d", &a);
			if (a > now) hi++;
			else if ( a < now) lo++;
			now = a;
		}
		printf("Case %d: %d %d\n", tc, hi, lo);
	}
	return 0;
}
		
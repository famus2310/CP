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
	int n, m;
	int boys = 0, girls = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		boys += a; girls += b;
	}
	int ans = boys / m + girls / m + (boys % m == 0 ? 0 : 1) + (girls % m == 0 ? 0 : 1);
	printf("%d\n", ans);
	return 0;
}
		
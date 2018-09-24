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

int t, n, m;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &m, &n);
		printf("%s", n % m == 0 ? "YES\n" : "NO\n");
	}
	return 0;
}
		
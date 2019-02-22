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
	int a, b, c, d;
	scanf("%d^%d %d^%d", &a, &b, &c, &d);
	if (b * log10(a) > d * log10(c))
		printf("%d^%d\n", a, b);
	else printf("%d^%d\n", c, d);
	return 0;
}
		
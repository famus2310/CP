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
const int LEVEL = 18;

LL table[N + 1][LEVEL + 1];

void build(int n, LL a1) {
	table[0][0] = INF;
	table[1][0] = a1;
	for (int i = 2; i <= n; i++) 
		table[i][0] = (table[i - 1][0] * 23 + 21563) % 16714589;

	for (int j = 1; j <= LEVEL; j++) {
		for (int i = 0; i + (1 << j) <= N; i++) {
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}

LL queryMin(int l, int r) {
	if (l > r)
		swap(l, r);
	int j = log2(r - l + 1);
	return min(table[l][j], table[r - (1 << j) + 1][j]);
}

int main() {
	int n, m;
	LL a1;
	scanf("%d %d %lld", &n, &m, &a1);
	build(n, a1);
	int now = 1;
	int u, v;
	scanf("%d %d", &u, &v);
	LL ans = queryMin(u, v);
	while (now < m) {
		u = ((17LL * u + 751 + ans + 2 * now) % n) + 1;
		v = ((13LL * v + 593 + ans + 5 * now) % n) + 1;
		ans = queryMin(u, v);
		now++;
		// cout << now << ": u = " << u << ", v = " << v << ", ans = " << ans << endl; 
	}
	printf("%d %d %lld\n", u, v, ans);
	return 0;
}
		
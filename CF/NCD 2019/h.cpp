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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL par[N];

LL findRoot(LL x) {
	return par[x] == x ? x : par[x] = findRoot(par[x]);
}

void uni(LL a, LL b) {
	LL root_a = findRoot(a);
	LL root_b = findRoot(b);
	par[root_a] = root_b;
}

void init() {
	for (int i = 0; i < N; i++)
		par[i] = i;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		LL n, m, q;
		scanf("%lld %lld %lld", &n, &m, &q);
		for (int i = 0; i < m; i++) {
			LL a, b;
			scanf("%lld %lld", &a, &b);
			uni(a, b);
		}
		string ans;
		while (q--) {
			LL a, b;
			scanf("%lld %lld", &a, &b);
			LL root_a = findRoot(a);
			LL root_b = findRoot(b);
			if (root_a == root_b)
				ans.pb('1');
			else ans.pb('0');
		}
		cout << ans << endl;
	}
	return 0;
}
		
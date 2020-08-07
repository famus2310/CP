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

map<LL, bool> umap;
LL n, m;

int main() {
	while (cin >> n >> m, n || m) {
		umap.clear();
		LL sum = 0;
		for (int i = 0; i < n; i++) {
			LL a;
			cin >> a;
			umap[a] = 1;
		}
		for (int j = 0; j < m; j++) {
			LL a;
			cin >> a;
			if (umap[a]) sum++;
		}
		cout << sum << endl;
	}
	return 0;
}
		
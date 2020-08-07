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

vector<pair<int, int> > v;

int manhattan(int xi, int yi, int xj, int yj) {
	return abs(xi - xj) + abs(yi - yj);
}

int main() {
	int n, m, k, q;
	scanf("%d %d %d %d", &n, &m , &k, &q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'X') v.pb({i + 1, j + 1}); 
		}
	}
	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		int ans = INF;
		for (int i = 0; i < v.size(); i++) {
			ans = min(ans, manhattan(x, y, v[i].first, v[i].second));
		}
		printf("%d\n", ans);
	} 
	return 0;
}
		
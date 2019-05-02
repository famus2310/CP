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

map<pair<int, int>, bool> plant;
LL n, m, k;

bool isBound(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		plant.clear();
		cin >> n >> m >> k;
		LL ans = 0LL;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			plant[{a, b}] = 1;
		}
		// if (k > n * m / 2) {
		// 	for (int i = 1; i <= n; i++) {
		// 		for (int j = 1; j <= m; j++) {
		// 			if (plant[{i, j}])
		// 				continue;
		// 			ans = ans + 4;
		// 			if (isBound(i - 1, j) && !plant[{i - 1, j}])
		// 				ans -= 2;
		// 			if (isBound(i, j - 1) && !plant[{i, j - 1}])
		// 				ans -= 2;
		// 		}
		// 		// cout << ans << endl;
		// 	}
		// } else {
			for (auto it : plant) {
				int i = it.first.first;
				int j = it.first.second;	
				ans = ans + 4;
				if (plant[{i - 1, j}])
					ans -= 2;
				if (plant[{i, j - 1}])
					ans -= 2;
			}
		// }
		cout << ans << endl;


	}
	return 0;
}

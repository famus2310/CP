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

int matA[505][505];
int matB[505][505];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &matA[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &matB[i][j]);

	for (int i = 0; i <= n + m; i++) {
		vector<int> v1, v2;
		for (int j = 0; j <= i; j++) {
			int x = i - j;
			int y = j;
			if (x >= n || y >= m)
				continue;
			v1.pb(matA[x][y]);
			v2.pb(matB[x][y]);
		}
		sort(all(v1));
		sort(all(v2));
		for (int j = 0; j < v1.size(); j++) {
			// cout << v1[j] << " " << v2[j] << endl;
			if (v1[j] != v2[j]) {
				puts("NO");
				return 0;
			}
		}
		// cout << endl;
	}
	puts("YES");
	return 0;
}
		
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int grid[1005][1005];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(grid, 0, sizeof(grid));
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				scanf(" %c", &c);
				if (c == 'P') grid[i][j] = 1;
				else grid[i][j] = 2;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int it = 0; it < n; it++) {
				if (grid[i][it] == 2) {
					bool found = 0;
					int pos;
					int move = 1;
					for (int j = it - 1; j >= 0 && move <= k; j++) {
						move++;
						if (grid[i][j] == 1) {
							found = 1;
							pos = j;
						}
					}
					if (found) {
						grid[i][pos] = 0;
						ans++;
					} else {
						move = 1;
						for (int j = it + 1; j < n && move <= k; j++) {
							move++;
							if (grid[i][j] == 1) {
								found = 1;
								pos = j;
							}
						}
						if (found) {
							grid[i][pos] = 0;
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
		
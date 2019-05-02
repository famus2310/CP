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

int grid[105][105];
int n, m, h;

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	fastio;
	cin >> n >> m >> h;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			grid[i][j] = h;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < n; j++) {
			grid[j][i] = min(grid[j][i], x);
		}
	}
	// output();
	// cout << endl;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < m; j++) {
			grid[i][j] = min(grid[i][j], x);
		}
	}
	// output();
	// cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if (x == 1)
				continue;
			else grid[i][j] = 0;;
		}
		// cout << endl;
	}
	output();
	return 0;
}
		
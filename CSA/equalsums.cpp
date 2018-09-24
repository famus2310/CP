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

int matrix[1005][1005], col[1005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			matrix[i][j] = max(matrix[i][j], matrix[j][i]);
		}
	}
	int maxCol = 0;
	for (int i = 0; i < n; i++) {
		col[i] = 0;
		for (int j = 0; j < n; j++) {
			col[i] += matrix[i][j];
		}
		maxCol = max(maxCol, col[i]);
	}
	for (int i = 0; i < n; i++) {
		if (col[i] != maxCol) matrix[i][i] += maxCol - col[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d%c", matrix[i][j], j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
		
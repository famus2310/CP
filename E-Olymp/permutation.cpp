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

int arr[N];
int table[N + 1][LEVEL + 1];

void build() {
	table[0][0] = INF;	
	for (int i = 0; i < N; i++)
		table[arr[i]][0] = i + 1;

	for (int j = 1; j < LEVEL; j++) {
		for (int i = 0; i + (1 << j) <= N; i++) {
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int queryMin(int l, int r) {
	int j = log2(r - l + 1);
	return min(table[l][j], table[r - (1 << j) + 1][j]);
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	build();
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", queryMin(a, b));
	}
	return 0;
}
		
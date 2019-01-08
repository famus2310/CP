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

int table[N + 1][LEVEL + 1];
int arr[N];

void build() {
	for (int i = 0; i < N; i++)
		table[i][0] = arr[i];

	for (int j = 1; j <= LEVEL; j++) {
		for (int i = 0; i + (1 << j) <= N; i++) {
			table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int queryMax(int l, int r) {
	if (l > r)
		swap(l, r);
	int j = log2(r - l + 1);
	return max(table[l][j], table[r - (1 << j) + 1][j]);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	build();
	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", queryMax(a - 1, b - 1));
	}
	return 0;
}

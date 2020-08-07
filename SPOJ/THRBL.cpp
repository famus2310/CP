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

int n, m;
int arr[50005];
int table[50005][25];

void build(int n) {
	for (int i = 0; i < n; i++)
		table[i][0] = arr[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++)
			table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
	}
}

int query(int a, int b, int n) {
	int ret = -(INF + 5);
	int k = log2(b - a + 1);
	return max(table[a][k], table[b - (1 << k) + 1][k]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	build(n);
	int ans = 0;
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		int lo = a;
		int hi = b;
		if (lo > hi) 
			swap(lo, hi);
		if (abs(lo - hi) < 2) {
			ans++;
		} else {
			int highest = query(lo + 1, hi - 1, n);
			// debug(highest);
			if (highest <= arr[a])
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
		
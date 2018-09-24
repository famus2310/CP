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
const int k = log2(N) + 1; 

int table[N][18];
int arr[N];
int LOG[N];

void init() {
	LOG[1] = 0;
	for (int i = 2; i < N; i++) 
		LOG[i] = LOG[i >> 1] + 1;
}

void build(int n) {
	for (int i = 0; i < n; i++)
		table[i][0] = arr[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r) {
	int j = LOG[r - l + 1];
	return min(table[l][j], table[r - (1 << j) + 1][j]);
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", arr + i);
	build(n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", query(a, b));
	}
	return 0;
}
		
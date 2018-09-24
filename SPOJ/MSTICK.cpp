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

int arr[N];
int LOG[N];
int min_table[N][25];
int max_table[N][25];

void init() {
	LOG[1] = 0;
	for (int i = 2; i < N; i++)
		LOG[i] = LOG[i >> 1] + 1;
}

void min_build(int n) {
	for (int i = 0; i < n; i++)
		min_table[i][0] = arr[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) 
			min_table[i][j] = min(min_table[i][j - 1], min_table[i + (1 << (j - 1))][j - 1]);
	}
}

void max_build(int n) {
	for (int i = 0; i < n; i++)
		max_table[i][0] = arr[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) 
			max_table[i][j] = max(max_table[i][j - 1], max_table[i + (1 << (j - 1))][j - 1]);
	}
}

int min_query(int a, int b) {
	int j = LOG[b - a + 1];
	return min(min_table[a][j], min_table[b - (1 << j) + 1][j]);
}

int max_query(int a, int b) {
	int j = LOG[b - a + 1];
	return max(max_table[a][j], max_table[b - (1 << j) + 1][j]);
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	min_build(n);
	max_build(n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int min_match_in_range = min_query(a, b);
		int max_match_in_range = max_query(a, b);
		double max_match1 = a == 0 ? -INF : max_query(0, a - 1) + min_match_in_range;
		double max_match2 = b == n - 1 ? -INF : max_query(b + 1, n - 1) + min_match_in_range;
		double max_match3 = (double)min_match_in_range + ((double)(max_match_in_range - min_match_in_range) / 2.0);
		printf("%.1lf\n", max(max_match1, max(max_match2, max_match3)));
	}
	return 0;
}
		
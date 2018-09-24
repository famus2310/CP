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

int table[N][18];
int arr[N];

void build() {
	for (int i = 0; i < N; i++)
		table[i][0] = arr[i]; 
	for (int j = 1; (1 << j) <= N; j++) {
		for (int i = 0; i + (1 << j) <= N; i++) {
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}

void query(int l, int r)	 {
	int ret = INF;
	for (int j = N; j >= 0; j--) {
		if (l + (1 << j) - 1 <= R) {
			ans = min(ans, table[l][j]);
			l += (1 << j);
		}
	}
}

void querymin(int l, int r) {
	int j = log2(r - l + 1);
	return min(table[l][j], table[r - (1 << l) + 1][j]);
}

int main() {

	return 0;
}
		
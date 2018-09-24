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

int solve(int n) {
	int ret = 0;
	while (n != 1) {
		if (n & 1) n = n * 3 + 1;
		else n = n >> 1;
		ret++;
	}
	return ret + 1;
}

int main() {
	int i, j;
	while (scanf("%d %d", &i, &j) == 2) {
		int mx = 0;
		int tmp1 = i, tmp2 = j;
		if (i > j) swap(i, j);
		while (i <= j) {
			mx = max(mx, solve(i));
			i++;
		}
		printf("%d %d %d\n", tmp1, tmp2, mx);
	}
	return 0;
}
		
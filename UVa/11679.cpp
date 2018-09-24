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

int bank[25];

int main() {
	int b, n;
	while (scanf("%d %d", &b, &n), (b || n)) {
		for (int i = 1; i <= b; i++) 
			scanf("%d", bank + i);
		for (int i = 0; i < n; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			bank[a] -= c;
			bank[b] += c;
		}
		bool ans = 1;
		for (int i = 1; i <= b; i++) {
			if (bank[i] < 0)
				ans = 0;
		}
		printf("%c\n", ans ? 'S' : 'N');
	}
	return 0;
}
		
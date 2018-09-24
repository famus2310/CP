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


int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int l, h, w;
		scanf("%d %d %d", &l, &w, &h);
		printf("Case %d: ", tc);
		if (l > 20 || h > 20 || w > 20)
			puts("bad");
		else 
			puts("good");
	}
	return 0;
}
		
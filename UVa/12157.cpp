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
		int n;
		scanf("%d", &n);
		int mile = 0, juice = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			mile += ((a / 30) + 1) * 10;
			juice += ((a / 60) + 1) * 15;
			// cout << mile << " " << juice << endl;
		}
		printf("Case %d: %s %d\n", tc, mile < juice ? "Mile" : mile > juice ? "Juice" : "Mile Juice", mile < juice ? mile : juice);
	}
	return 0;
}
		

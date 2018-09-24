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
	int n, m, vx, vy, px, py;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &vx, &vy);
	scanf("%d %d", &px, &py);
	int ans;
	if (vx == px) {
		if (vy == py) 
			ans = 0;
		else if (vy > py) 
			ans = vy;
		else 
			ans = n - vy;
	} else if (vy == py) {
		if (vx > px) 
			ans = vx;
		else 
			ans = m - vx;
	} else if (vx > px) {
		if (vy > py) 
			ans = max(vx, vy);
		else
			ans = max(vx, abs(m - vy + 1));
	} else if (vx < px) {
		if (vy > py) 
			ans = max(abs(n - vx + 1), vy);
		else
			ans = max(abs(n - vx + 1), abs(m - vy + 1));
	}  
	printf("%d\n", ans);
	return 0;
}
		
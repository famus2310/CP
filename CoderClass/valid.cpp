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
	unsigned long long x, y;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%llu %llu", &x, &y);
		// unsigned long long tmpx = x >> 1, tmpy = y >> 1;
		string win;
		if (x - 2ULL >= y) win = "Toni";
		else if (y - 2ULL >= x) win = "Tere";
		else win = "Voting Ulang";
		cout << win << endl;
	}
	return 0;
}

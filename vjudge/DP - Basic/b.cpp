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

map<LL, LL> coins;

LL solve(LL x) {
	if (x == 1)
		return 1;
	if (coins.find(x) != coins.end())
		return coins[x];
	else return coins[x] = max(x, solve(x / 2) + solve(x / 3) + solve(x / 4));
}

int main() {
	LL x;
	while (scanf("%lld", &x) == 1) {
		printf("%lld\n", solve(x));
	}
	return 0;
}
		
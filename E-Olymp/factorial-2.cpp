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

const int NMAX = 1e5 + 5;


int main() {
	fastio;
	LL n;
	cin >> n;
	double ans = 0;
	auto t = clock();
	for (LL i = 1; i <= n; i++) {
		ans += log10(i);
	}
	LL ret = floor(ans + 1);
	cout << ret << endl;
	//cout << ((double)(clock() - t )/ CLOCKS_PER_SEC) << endl;
	return 0;
}
		
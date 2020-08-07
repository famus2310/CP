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

int solve(double n, double k) {
	int ret = 0;
	n = n / k;
	while (n > 1) {
		ret++;
		n = n / k;
	}
	return ret;
}

int main() {
	double n, k;
	scanf("%lf %lf", &n, &k);
	printf("%d\n", solve(n, k));
	return 0;
}
		
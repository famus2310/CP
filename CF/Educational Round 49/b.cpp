#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
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
	LL n, q;
	scanf("%llu %llu", &n, &q);
	while (q--) {
		LL a, b;
		scanf("%llu %llu", &a, &b);
		if (a & 1 && b & 1) {
			LL now = (a / 2) * n + ((b + 1)/ 2);
			printf("%llu\n", now);
		} else if (a & 1 && b % 2 == 0) {
			LL now = ((n + 1) / 2) * ((n + 1) / 2) + (n / 2) * (n / 2) + n * (a / 2) + (b / 2);
			printf("%llu\n", now);
		} else if (a % 2 == 0 && b & 1) {
			LL now = ((n + 1) / 2) * ((n + 1) / 2) + (n / 2) * (n / 2) + (n / 2) + ((b + 1) / 2) + n * (a / 2 - 1);
			printf("%llu\n", now);
		} else {
			LL now = ((a - 1) / 2) * n + ((n + 1)/ 2) + ((b + 1) / 2);
			printf("%llu\n", now);
		}
	}
	return 0;
}
		
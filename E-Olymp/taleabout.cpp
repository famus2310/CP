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
	int n;
	scanf("%d", &n);
	LL now = 1;
	while (n--) {
		now++;
		now = now << 1;
	}
	printf("%llu\n", now);
	return 0;
}
		
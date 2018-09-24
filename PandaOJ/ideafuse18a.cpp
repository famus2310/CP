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

const int N = 1e6 + 5;

bool num[N];

int main() {
	LL i = 1;
	LL now = 1;
	while (now <= 1000000) {
		num[now] = 1;
		++i;
		now += i;
	}
	LL t;
	scanf("%lld", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL n;
		scanf("%lld", &n);
		printf("Case #%d: ", tc);
		if (num[n]) puts("YES");
		else puts("NO");
	}
	return 0;
}
		
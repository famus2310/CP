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

const LL NMAX = 1e10 + 5;

map<LL, LL> mp;

int main() {
	LL last = 1;
	LL now = 2;
	mp[0] = 1;
	mp[1] = 1;
	while (now < NMAX) {
		mp[now] = 1;
		LL tmp = now;
		now += last;
		last = tmp;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n;
		scanf("%lld", &n);
		if (mp[n]) puts("IsFibo");
		else puts("IsNotFibo");
	}
	return 0;
}
		
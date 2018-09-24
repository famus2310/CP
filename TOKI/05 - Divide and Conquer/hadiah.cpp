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

const int N = 1e7 + 5;

LL precomp[N];
bool vis[N];

LL phi(LL n) {
	LL ret = n;
	for (LL i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			ret -= ret / i;
		}
	}
	if (n > 1) ret -= ret / n;
	return ret;
}

LL modex(LL a, LL b, LL c) {
	LL ret = 1;
	a = a % c;
	while (b) {
		if (b & 1) ret = (ret * a) % c;
		b = b >> 1;
		a = (a * a) % c;
	}
	return ret;
}

LL precompute (LL a, LL n) {
	LL ret = 1;
	a %= n;
	while (vis[a] == 0) {
		vis[a] = 1;
		precomp[ret] = 
	}
}


int main() {
	LL a, b, c, n;
	return 0;
}
		
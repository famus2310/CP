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

LL start, finish;

int main() {
	LL h, m, s;
	scanf("%lld:%lld:%lld", &h, &m, &s);
	start = 3600 * h + 60 * m + s;
	scanf("%lld:%lld:%lld", &h, &m, &s);
	finish = 3600 * h + 60 * m + s;
	if (start >= finish) {
		finish += 24 * 3600;
	}
	LL ans = finish - start;
	h = ans / 3600;
	ans -= h * 3600;
	m = ans / 60;
	ans -= m * 60;
	s = ans;
	printf("%02lld:%02lld:%02lld\n", h, m, s);
	return 0;
}
			
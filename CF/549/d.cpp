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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	LL cities = n * k;
	LL a, b;
	scanf("%lld %lld", &a, &b);
	LL s1 = a;
	LL s2 = k - a;
	LL mx = -INF64;
	LL mn = INF64;
	for (LL i = 0; i < n; i++) {
		LL now1 = i * k + b - s1;
		LL now2 = (i + 1) * k - b - s1;
		LL cur1 = i * k + b - s2;
		LL cur2 = (i + 1) * k - b - s2;
		if (now1 <= 0)
			now1 += cities;
		if (now2 <= 0)
			now2 += cities;
		if (cur1 <= 0)
			cur1 += cities;
		if (cur2 <= 0)
			cur2 += cities;
		
		// cout << now1 << " " << now2 << " " << cur1 << " " << cur2 << endl;
		LL g1 = __gcd(now1, cities);
		LL g2 = __gcd(now2, cities);
		LL g3 = __gcd(cur1, cities);
		LL g4 = __gcd(cur2, cities);
		// cout << "gcd : " << g1 << " " << g2 << " " << g3 << " " << g4 << endl;
		LL tmp1 = cities / g1;
		LL tmp2 = cities / g2;
		LL tmp3 = cities / g3;
		LL tmp4 = cities / g4;
		// cout << "tmp : " << tmp1 << " " << tmp2 << " " << tmp3 << " " << tmp4 << endl;  
		mx = max(tmp1, mx);
		mn = min(mn, tmp1);
		mx = max(tmp2, mx);
		mn = min(mn, tmp2);
		mx = max(tmp3, mx);
		mn = min(mn, tmp3);
		mx = max(tmp4, mx);
		mn = min(mn, tmp4);
	}
	printf("%lld %lld\n", mn, mx);
	return 0;
}
		
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

pair<LL, LL> solve(LL a, LL b, LL c, LL d) {
	if (a % 2 == c % 2) {
		LL white = ((b - a + 1) * (d - c + 1) + 1LL) / 2LL;
		LL black = ((b - a + 1) * (d - c + 1)) / 2LL;
		// cout << white << " " << black << endl;
		return {white, black};
	} else {
		LL white = ((b - a + 1) * (d - c + 1)) / 2LL;
		LL black = ((b - a + 1) * (d - c + 1) + 1LL) / 2LL;
		return {white, black};
	}
}


bool check(const pair<LL, LL>& p) {
	return p.first >= 0 && p.second >= 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, m;
		scanf("%lld %lld", &m, &n);
		LL w = (m * n + 1LL) / 2LL;
		LL b = (m * n) / 2LL;
		LL x1, x2, y1, y2;
		LL x3, x4, y3, y4;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
		pair<LL, LL> big1 = solve(y1, y2, x1, x2);
		pair<LL, LL> big2 = solve(y3, y4, x3, x4);
		pair<LL, LL> interup = solve(y4 + 1, y2, x1, x2);
		pair<LL, LL> interright = solve(y1, y2, x4 + 1, x2);
		pair<LL, LL> interleft = solve(y1, y2, x1, x3 - 1);
		pair<LL, LL> interbot = solve(y1, y3 - 1, x1, x2);
		b += big2.first;
		w -= big2.first;
		// cout << w << " " << b << endl;
		// cout << big2.first << " " << big2.second << endl;
		if (check(interup)) {
			w += interup.second;
			b -= interup.second;
		}
		// cout << w << " " << b << endl;
		if (check(interleft)) {
			w += interleft.second;
			b -= interleft.second;
		}
		// cout << w << " " << b << endl;
		if (check(interright)) {
			w += interright.second;
			b -= interright.second;
		}
		// cout << w << " " << b << endl;
		if (check(interbot)) {
			w += interbot.second;
			b -= interbot.second;
		}
		// cout << w << " " << b << endl;
		if (check(interup) && check(interleft)) {
			pair<LL, LL> tmp = solve(y4 + 1, y2, x1, x3 - 1);
			w -= tmp.second;
			b += tmp.second;
		}
		// cout << w << " " << b << endl;
		if (check(interup) && check(interright)) {
			pair<LL, LL> tmp = solve(y4 + 1, y2, x4 + 1, x2);
			w -= tmp.second;
			b += tmp.second;
		}
		// cout << w << " " << b << endl;
		if (check(interright) && check(interbot)) {
			pair<LL, LL> tmp = solve(y1, y3 - 1, x4 + 1, x2);
			w -= tmp.second;
			b += tmp.second;
		}
		// cout << w << " " << b << endl;
		if (check(interbot) && check(interleft)) {
			pair<LL, LL> tmp = solve(y1, y3 - 1, x1, x3 - 1);
			w -= tmp.second;
			b += tmp.second;
		}
		// cout << w << " " << b << endl;
		printf("%lld %lld\n", w, b);
	}
	return 0;
}
		
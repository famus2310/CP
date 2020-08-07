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

LL toDec(const string& s) {
	LL ret = 0LL;
	LL mul = 1LL;
	for (int i = s.size() - 1; i >= 0; i--) {
		ret = ret + (s[i] == '1') * mul;
		mul = mul << 1;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int a, b, c, d;
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);
		string s;
		cin >> s;
		int sa, sb, sc, sd;
		sa = toDec(s.substr(0, 8));
		sb = toDec(s.substr(9, 8));
		sc = toDec(s.substr(18, 8));
		sd = toDec(s.substr(27, 8));
		printf("Case %d: ", tc);
		if (sa != a || sb != b || sc != c || sd != d)
			puts("No");
		else puts("Yes");
	}
	return 0;
}
		
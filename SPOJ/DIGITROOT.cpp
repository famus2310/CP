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

string a, b;

LL SumOfDigit(LL x) {
	LL ret = x;
	while (ret > 9) {
		x = ret;
		ret = 0LL;
		while (x) {
			ret += x % 10;
			x /= 10;
		}
	}
	return ret;
}

LL SumOfDigit(const string& s) {
	LL ret = 0LL;
	for (int i = 0; i < s.size(); i++)
		ret += s[i] - '0';
	return SumOfDigit(ret);
}


LL BigMod(const string& s) {
	LL ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret = (ret * 10 + s[i] - '0') % 6;
	}
	return ret;
}

LL Power(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = ret * a;
		b = b >> 1;
		a = a * a;
	}
	return ret;
}

int main() {
	cin >> a >> b;
	LL x = SumOfDigit(a);
	LL y = BigMod(b);
	if (x == 9) {
		puts("9");
	} else if (b != "1" && (x == 3 || x == 6)) {
		puts("9");
	} else {
		printf("%lld\n", SumOfDigit(Power(x, y)));
	}
	return 0;
}
		
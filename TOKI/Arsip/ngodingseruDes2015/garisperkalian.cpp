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

const int N = 1e5 + 5;

LL n;

string printNum(LL a) {
	string ret = "";
	while (a > 9) {
		ret += (char)(9 + '0');
		a -= 9;
	}
	if (a > 0) {
		ret += (char)(a + '0');
	}
	if(ret.empty()) return "0";
	return ret;
}

int main() {
	cin >> n;
	if (n == 0) {
		cout << "0 0" << endl;
		return 0;
	}
	LL hi = n;
	LL lo = 1;
	while (lo < hi && hi > 9 * 18) {
		LL div = hi;
		for (int i = 2; i <= sqrt(hi); i++) {
			if (hi % i != 0) continue;
			else {
				div = i;
				break;
			}
		}
		lo *= div;
		hi /= div;
	}
	if (lo > hi || lo > 9 * 18) {
		cout << "-1" << endl;
		return 0;
	}
	string ans1 = printNum(lo);
	string ans2 = printNum(hi);
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
		
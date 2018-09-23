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

LL countDig(LL a) {
	LL ret = 0;
	while (a) {
		ret++;
		a /= 10;
	} 	
	return ret;
}

int main() {
	LL a, b, c, k;
	cin >> a >> b >> c >> k;
	LL tmp1 = abs(a - b);
	LL tmp2 = k + 1;
	if (countDig(tmp1) + countDig(tmp2) - 1 >= 18) {
		cout << "unfair" << endl;
	} else {
		cout << (b - a) * (k + 1) << endl;
	}
	return 0;
}
		
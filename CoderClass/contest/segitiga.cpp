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

void checker(LL* side) {
	sort(side, side + 3);
	LL a = side[0];
	LL b = side[1];
	LL c = side[2];
	if (a + b < c || a + c < b || b + c < a) puts("bukan segitiga");
	else if (a + b == c) puts("garis lurus");
	else if (a == b && b == c) puts("segitiga sama sisi");
	else if (a == b || a == c || b == c) puts("segitiga sama kaki");
	else if (a * a + b * b == c * c) puts("segitiga siku-siku");
	else puts("segitiga sembarang");
}

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL s[3];
		for (int i = 0; i < 3; i++)
			scanf("%lld", s + i);
		checker(s);
	}
	return 0;
}
		
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

LL arr[3][11];

int main() {
	arr[1][0] = 285120;
	for (int i = 1; i <= 10; i++) {
		if (i & 1) arr[1][i] = 296640;
		else arr[1][i] = 299520;
	}
	arr[2][0] = 194505988824000;
	arr[2][10] = 194379965136000;
	arr[2][9] = 194367105576000;
	arr[2][8] = 194382537048000;
	arr[2][7] = 194369677488000;
	arr[2][6] = 194385108960000;
	arr[2][5] = 194372249400000;
	arr[2][4] = 194387680872000;
	arr[2][3] = 194374821312000;
	arr[2][2] = 194390252784000;
	arr[2][1] = 194377393224000;
	LL tmp = 0;
	LL k, m;
	LL t;
	scanf("%lld", &t);
	while (t--){
		scanf("%lld %lld", &k, &m);
		printf("%lld\n", arr[k][m]);
	}
}


// 20! / 2^10 - 19!/2^9
// 19! * 10 - 19!/ 2 ^ 9
// 19! * 9 / 2 ^ 9
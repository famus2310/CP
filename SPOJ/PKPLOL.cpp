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
string disp[10];

// a
//f b
// g
//e c
// d

int main() {
	//        a   b  c  d  e  f  g
	disp[0] = "abcdef";
	disp[1] = "bc";  
	disp[2] = "abdeg";
	disp[3] = "abcdg";
	disp[4] = "bcfg";
	disp[5] = "acdfg";
	disp[6] = "acdefg";
	disp[7] = "abc";
	disp[8] = "abcdefg";
	disp[9] = "abcdfg"; 
	scanf("%lld", &n);
	for (int tc = 1; tc <= n; tc++) {
		LL a;
		scanf("%lld", &a);
		cout << "Case " << tc << ": " << disp[a] << endl;
	}
	return 0;
}
		
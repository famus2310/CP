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
	fastio;
	LL n;
	cin >> n;
	LL last2 = -1;
	LL last1 = -1;
	LL ret = 0LL;
	bool inf = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if ((last1 == 2 && a == 3) || (a == 2 && last1 == 3))
			inf = 1;
		if ((last1 == 1 && a == 2) || (a == 1 && last1 == 2))
			ret = ret + 3;
		if ((last1 == 1 && a == 3) || (a == 1 && last1 == 3))
			ret = ret + 4;
		if (last2 == 3 && last1 == 1 && a == 2)
			ret = ret - 1;
		last2 = last1;
		last1 = a;
	}
	if (inf)
		cout << "Infinite" << endl;
	else cout << "Finite\n" << ret << endl;
	return 0;
}
		
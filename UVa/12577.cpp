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

string s;

int main() {
	int tc = 1;
	while (cin >> s, s != "*") {
		printf("Case %d: ", tc++);
		if (s[0] == 'H')
			puts("Hajj-e-Akbar");
		else 
			puts("Hajj-e-Asghar");
	}
	return 0;
}
		
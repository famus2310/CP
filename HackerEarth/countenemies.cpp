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


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		int xs = 0, os = 0;
		int ans = 0;
		for (char c : s) {
			if (c == '*') {
				if (xs == 0) ans += os;
				xs = os = 0;
			} else if (c == 'X') xs++;
			else os++;
		}
		if (xs == 0) ans+= os;
		printf("%d\n", ans);
	}
	return 0;
}
		
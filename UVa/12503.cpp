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

int mv[105];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int x = 0;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			if (s[0] == 'L') {
				mv[i] = -1;
			} else if (s[0] == 'R') {
				mv[i] = 1;
			} else {
				string as;
				cin >> as;
				int val;
				scanf("%d", &val);
				mv[i] = mv[val];
			}
			x += mv[i];
			// debug(x);
		}
		printf("%d\n", x);
	}
	return 0;
}
		
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


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		int n;
		scanf("%d", &n);
		int x = 0;
		if (s[0] == 'n') {
			x--;
		} else
			x++;
		int now = (n + x + 100) % 100;
		printf("%d\n", now);
	}
	return 0;
}
		
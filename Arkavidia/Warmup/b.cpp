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
		int x, n;
		string s;
		cin >> x >> n >> s;
		if (s[0] == 'A' || s[0] == 'O') {
			for (int i = 0; i < n; i++)
				printf("%d%c", x, i == n - 1 ? '\n' : ' ');
		} else {if (n & 1) {
				printf("%d", x);
				for (int i = 1; i < n; i++)
					printf(" %d", x);
				puts("");
			} else {
				int now = log2(x);
				now = 1 << now;
				printf("%d %d", now, now ^ x);
				for (int i = 2; i < n; i++) {
					printf(" %d", 1);
				}
				puts("");
			}
		}
	}
	return 0;
}
//011
//110
//
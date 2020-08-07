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
	int n;
	while (scanf("%d", &n) == 1, n != 0) {
		int lastR = -1;
		int lastD = -1;
		bool foundZ = 0;
		int mn = INF;
		for (int i = 0; i < n; i++) {
			char c;
			scanf(" %c", &c);
			if (c == 'R') {
				if (lastD != -1) {
					mn = min(mn, abs(lastD - i));
				}
				lastR = i;
			} else if (c == 'D') {
				if (lastR != -1) {
					mn = min(mn, abs(lastR - i));
				}
				lastD = i;
			} else if (c == 'Z') {
				foundZ = 1;
				mn = 0;
			}
		}
		printf("%d\n", mn);
	}
	return 0;
}
		
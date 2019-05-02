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

bool dp[10][10][10][10][2];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string a;
		int n;
		cin >> a >> n;
		dp[a[0] - '0'][a[1] - '0'][a[2] - '0'][a[3] - '0'][0] = 1;
		int now = 0;
		for (int i = 0; i < n; i++) {
			now = now ^ 1;
			for (int a = 0; a < 10; a++) {
				for (int b = 0; b < 10; b++) {
					for (int c = 0; c < 10; c++) {
						for (int d = 0; d < 10; d++) {
							if (dp[(a + 9) % 10])
						}
					}
				}
			}
		}
	}
	return 0;
}
		
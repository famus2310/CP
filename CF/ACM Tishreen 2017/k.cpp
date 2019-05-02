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

LL dp[55][55]; //start, length
LL prefix[55];
LL s[55];
string inp;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(dp, 0);
		prefix[0] = 0;
		cin >> inp;
		int sz = inp.size();
		for (int i = 1; i <= sz; i++) {
			s[i] = inp[i - 1] - '0';
			prefix[i] = prefix[i - 1] + s[i];
		}
		for (int i = 1; i <= sz; i++) {
			dp[i][0] = 1;
			dp[i][1] = 1;
		}
		for (int i = 2; i <= sz; i++) {
			for (int j = 1; j + i - 1 <= sz; j++) {
				dp[j][i] = 1;
				int rg = j;
				int lf = j + i - 1;
				for (int k = rg; k < lf; k++) {
					for (int l = lf; l > rg; l--) {
						if (l <= k)
							break;
						LL sumlf = prefix[lf] - prefix[l - 1];
						LL sumrg = prefix[k] - prefix[rg - 1];
						if (sumlf == sumrg)
							dp[j][i] = (dp[j][i] + dp[k + 1][l - k - 1]) % MOD;
							// cout << k << " " << l << " : " << dp[j][i] << " ";
					}
				}
			}
		}
		printf("%lld\n", dp[1][sz]);
	}
	return 0;
}
		
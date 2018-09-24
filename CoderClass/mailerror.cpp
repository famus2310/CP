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

string a, b;

LL LCS() {
	LL cnt[a.size() + 1][b.size() + 1];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i <= a.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
			if (i == 0 || j == 0) cnt[i][j] = 0;
			else {
				if (a[i - 1] == b[j - 1]) cnt[i][j] = cnt[i - 1][j - 1] + 1;
				else cnt[i][j] = max(cnt[i - 1][j], cnt[i][j - 1]);
			}
		}
	}
	return cnt[a.size()][b.size()];
}

int main() {
	cin >> a >> b;
	printf("%lld\n", LCS());
	return 0;
}
		
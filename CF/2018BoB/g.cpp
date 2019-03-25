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

LL now[N];
LL diff[N];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL ret = 0LL;
		LL n;
		cin >> n;
		string s;
		cin >> s;
		now[0] = n * (n + 1) / 2;
		diff[0] = now[0] - (n + 1);
		ret = (ret + now[0] * (LL)(s[0])) % MOD;
		ret = (ret + now[0] * (LL)(s.back())) % MOD;
		for (int i = 1; i < n / 2; i++) {
			now[i] = now[i - 1] + diff[i - 1];
			diff[i] = max(0LL, diff[i - 1] - (n + 1));
				// debug(now[i]);
			ret = (ret + 1LL * now[i] * s[i]) % MOD;
			ret = (ret + 1LL * now[i] * s[s.size() - i - 1]) % MOD;
		}
		now[n / 2] = now[n / 2 - 1] + diff[n / 2 - 1];
		if (n & 1)
			ret = (ret + ((now[n / 2]) * s[n / 2]) + MOD ) % MOD;
		if (n == 1) ret = s[0];
		cout << "Case " << tc << ": " << ret << endl;
	}
	return 0;
}
		
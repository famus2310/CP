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

LL dp[205];

int main() {
	fastio;
	int n;
	cin >> n;
	while (n--) {
		dp[0] = 0;
		string s;
		cin >> s;
		for (int i = 1; i <= s.size(); i++) {
			dp[i] = 0;
			LL now = 0;
			LL lim = (1LL << 31) - 1;
			LL mult = 1;
			for (int j = i - 1; j >= 0; j--) {
				char x = s[j];
				if (x == '0' && j != i - 1) {
					mult = mult * 10;
					continue;
				}
				now = (x - '0') * mult + now;
				if (now > lim || mult > lim)
					break;
				dp[i] = max(dp[i], dp[j] + now);
				mult = mult * 10;
			}
		}
		cout << dp[s.size()] << endl;
	}
	return 0;
}

/*
6
1234554321
5432112345
000
121212121212
2147483648
11111111111111111111111111111111111111111111111111111
*/
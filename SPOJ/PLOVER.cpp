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

LL dp[45][95][5];
LL n, k;

bool isPrime(LL x) {
	if (x == 0)
		return false;
	if (x == 1)
		return false;
	if (x == 2)
		return true;
	if (x == 3)
		return true;
	for (LL i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

LL solve(LL now, LL sum, LL last) {
	LL &ans = dp[now][sum][last];
	if (now == 34) {
		if (isPrime(sum)) {
			// cout << now << " " << sum << " " << last << endl;
			return ans = 1;
		}
		else return ans = 0;
	}
	if (ans != -1)
		return ans;
	ans = 0;
	for (LL i = 0; i < 3; i++)
		ans += solve(now + 1, sum + i, i);
	return ans;
}

string calc(LL now, LL rem, LL sum, string ans) {
	if (now == 35)
		return ans; 
	// cout << now << " " << rem << " " << sum << " " << ans << endl;
	// debug(solve(now, sum, 1));
	if (solve(now, sum, 0) < rem)
		rem -= solve(now, sum, 0);
	else return calc(now + 1, rem, sum, ans + "0");
	if (solve(now, sum + 1, 1) < rem)
		rem -= solve(now, sum + 1, 1);
	else return calc(now + 1, rem, sum + 1, ans + "1");
	return calc(now + 1, rem, sum + 2, ans + "2");
}

LL toDec(string& s) {
	LL ret = 0LL;
	LL mult = 1LL;
	reverse(all(s));
	for (char c : s) {
		ret = ret + (c - '0') * mult;
		mult = mult * 3;
	}
	return ret;
}

int main() {
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 95; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	solve(1, 0, 0);
	// for (int i = 34; i > 0; i--) {
	// 	cout << dp[i][0][0] << endl;
	// }
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &k);
		LL mn = -1;
		for (LL i = 34; i > 0; i--) {
			// debug(i);
			if (dp[i][0][0] > k) {
				mn = i;
				break;
			}
		}
		if (mn == -1) {
			printf("-1\n");
			continue;
		}
		string cur = calc(mn, k, 0, "");
		// cout << "test" << endl;
		LL ans = toDec(cur);
		if (ans > n)
			ans = -1;
		printf("%lld\n", ans);
	}
	return 0;
}
		
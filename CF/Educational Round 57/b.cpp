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

int cnt[35];
string s;

int main() {
	SET(cnt, 0);
	LL n;
	scanf("%lld", &n);
	cin >> s;
	char fr = s[0];
	char bk = s.back();
	LL cntFr = 0;
	while (cntFr + 1< s.size() && s[cntFr + 1] == fr)
		cntFr++;
	LL cntBk = s.size() - 1;
	while (cntBk - 1>= 0 && s[cntBk - 1] == bk) {
		cntBk--;
	}
	LL ans = 1;
	if (cntBk < cntFr) {
		ans = 1LL * n * (n + 1) / 2;
		ans = ans % 998244353;
	} else if (fr == bk) {
		ans = ans + cntFr + s.size() - cntBk + 1; 
		ans = ans % 998244353;
		ans = ans + (cntFr + 1) * (s.size() - cntBk);
		ans = ans % 998244353;
	} else {
		ans = ans + cntFr + s.size() - cntBk + 1;
	}
	ans = ans % 998244353;
	printf("%lld\n", ans);
	return 0;
}
		
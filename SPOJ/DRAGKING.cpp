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

string s;

LL countPal(LL i, LL j) {
	if (i < 0 || j >= s.size() || s[i] != s[j]) return 0;
	return ((j - i) + 1) * ((j - i) + 1) * ((j - i) + 1) + countPal(i - 1, j + 1); 
}


int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		cin >> s;
		LL ans = 0;
		for (int i = 0; i < s.size(); i++) {
			ans += countPal(i, i) + countPal(i, i + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		
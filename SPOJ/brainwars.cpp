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

string hexto11(const string& s) {
	LL dec = 0LL;
	LL mult = 1LL;
	for (int i = s.size() - 1; i >= 0; i--) {
		dec = dec + mult * s[i];
		mult = mult << 4;
	}
	string ret;
	while (dec) {
		LL now = dec % 11;
		char pushed;
		if (now == 10)
			pushed = 'A'
		else pushed = now + '0';
		ret.pb(pushed);
		dec = dec / 11;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	
	return 0;
}
		
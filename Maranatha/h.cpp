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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

void scanint (LL &x) {
	LL c = getchar();
	x = 0LL;
	 LL neg = 0LL;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar());
	if (c == '-') {
		neg = 1; 
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
		x = (x << 1LL) + (x << 3LL) + c - 48;
	if (neg) x = -x;
}

unordered_map<string, bool> card;

int main() {
	LL t;
	// fastio;
	scanint(t);
	while (t--) {
		card.clear();
		LL res = 0LL;
		LL n;
		// cin >> n;
		scanint(n);
		for (LL i = 0; i < n; i++) {
			string tmp;
			char c = getchar();
			tmp.pb(c);
			if (c == '1') {
				c = getchar();
				tmp.pb(c);
			}
			c = getchar();
			tmp.pb(c);
			c = getchar();
			if (card[tmp]) continue;
			else {
				res++;
				card[tmp] = 1;
			}
		}
		if (res == 52) {
			printf("FULLHOUSE %lld", n - 52);
		} else printf("INCOMPLETE");
		if (t != 0) printf("\n");
	}
	return 0;
}	
		
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

string s;
int snow = 0;
int cane = 0;
int ch = 0;

int main() {
	cin >> s;
	int n = s.size();
	for (char c : s) {
		if (c == '*')
			snow++;
		else if (c == '?')
			cane++;
		else ch++;
	}
	int k;
	scanf("%d", &k);
	int snowAdd = 0;
	int rem = 0;
	if (ch < k) {
		snowAdd = k - ch;
	} else if (ch > k) {
		rem = ch - k;
	}
	string ans;
	for (char c : s) {
		if (c == '*') {
			if (snowAdd > 0) {
				while (snowAdd > 0) {
					ans.pb(ans.back());
					snowAdd--;
				}
			}
			else if (rem > 0) {
				ans.pop_back();
				rem--;
			}
		} else if (c == '?') {
			if (rem > 0) {
				ans.pop_back();
				rem--;
			}
		} else ans.pb(c);
	}
	if (snowAdd || rem) {
		puts("Impossible");
	} else cout << ans << endl;
	return 0;
}
		
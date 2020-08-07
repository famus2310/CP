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

string s;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		string ans;
		int now = 0;
		bool space = 0;
		for (char c : s) {
			if (c == '/') {
				if (space) {
					ans.pb(' ');
					space = 0;
					continue;
				}
				ans.pb((char)(now + 'A' - 1	));
				now = 0;
			} else if (c == '#') {
				space = 1;
			} else {
				now = now * 2;
				if (c == '-')
					now++;
			}
			// debug(now);
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
/*
3
--..-/.----/..---/--..-/....-/.-.--/....-/-..-./-.-../....-/
-.--./.----/...--/.----/.--.-/..--./..-.-/-..--/-.-../
..---/-.-.-/..-../..-.-/..---/
*/
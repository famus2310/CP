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
	fastio;
	int n;
	cin >> n;
	if (n & 1) {
		cout << ":(" << endl;
		return 0;
 	}
 	int needopen = n / 2;
 	int needclose = n / 2;
 	cin >> s;
 	for (char c : s) {
 		if (c == '(')
 			needopen--;
 		if (c == ')')
 			needclose--;
 	}
 	if (needopen < 0 || needclose < 0) {
 		cout << ":(" << endl;
 		return 0;
 	}
 	for (char &c : s) {
 		if (c != '?')
 			continue;
 		if (needopen) {
 			c = '(';
 			needopen--;
 		} else c = ')';
 	}
 	int now = 0;
 	for (int i = 0; i < s.size() - 1; i++) {
 		char c = s[i];
 		if (c == '(')
 			now++;
 		else now--;
 		if (now <= 0) {
 			cout << ":(" << endl;
 			return 0;
 		}
 	}
 	cout << s << endl;
	return 0;
}
		
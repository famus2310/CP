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

int main() {
	cin >> s;
	char now = 'a';
	int pos = -1;
	for (int i = 0; i < s.size(); i++) {
		// cout << i << now << endl;
		if (now == 'z' && s[i] <= now) {
			s[i] = now;
			pos = 1;
			break;
		} else if (s[i] <= now) {
			s[i] = now;
			now++;
		}
	}
	if (pos == -1 || s.size() < 26) {
		printf("%d\n", pos);
		return 0;
	}
	cout << s << endl;
	return 0;
}
		
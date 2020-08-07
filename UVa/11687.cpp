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

int countDig(int x) {
	int ret = 0;
	while (x) {
		ret++;
		x /= 10;
	}
	return ret;
}

int main() {
	while (cin >> s, s[0] != 'E') {
		// if (s == "1") puts ("1");
		int cnt = 1;
		string last = s;
		string now = to_string(s.size());
		while (true) {
			if (now == last) break;
			last = now;
			now = to_string(last.size());
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
		
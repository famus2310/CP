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

int n, k;
int counter = 0;

bool check(const string& s) {
	int a = 0;
	int b = 0;
	int c = 0;
	for (char x : s) {
		if (x == 'a')
			a++;
		if (x == 'b')
			b++;
		if (x == 'c')
			c++;
	}
	return a + b == c;
}

void rec(int now, string s) {
	if (now == n) {
		// cout << s << endl;
		bool ans = 1;
		for (int i = 0; i <= n - k; i++) {
			string tmp = s.substr(i, k);
			if (!check(tmp))
				ans = 0;
		}
		if (ans)
			counter++;
		return;
	}
	rec(now + 1, s + "a");
	rec(now + 1, s + "b");
	rec(now + 1, s + "c");
}

int main() {
	fastio;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= i; j++) {
			// if (i % 2 == - || j & 1)
			// 	continue;
			counter = 0;
			n = i;
			k = j;
			rec(0, "");
			cout << counter << " ";
		}
		cout << endl;
 	}
	

	return 0;
}
		
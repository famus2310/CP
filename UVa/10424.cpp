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

string a, b;

int simplifies(int x) {
	while (x > 9) {
		int tmp = 0;
		while (x) {
			tmp += x % 10;
			x /= 10;
		}
		x = tmp;
	}
	return x;
}

int calculate(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i]))
			ret += s[i] - 'A' + 1;
		else if (islower(s[i]))
			ret += s[i] - 'a' + 1;
 	}
 	return simplifies(ret);
}

int main() {
	while (getline(cin, a)) {
		getline(cin, b);
		int x = calculate(a);
		int y = calculate(b);
		if (x > y) swap(x, y);
		printf("%.2lf %%\n",(double)x / (double)y * 100.0);
	}
	return 0;
}
		
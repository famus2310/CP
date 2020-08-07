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
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> s;
		char ans;
		int sz = s.size();
		if (s == "1" || s == "4" || s == "78")
			ans = '+';
		else if (sz > 1 && s[sz - 2] == '3' && s[sz - 1] == '5')
			ans = '-';
		else if (sz > 1 && s[0] == '9' && s[sz - 1] == '4')
			ans = '*';
		else 
			ans = '?';
		printf("%c\n", ans);
	}
	return 0;
}
		
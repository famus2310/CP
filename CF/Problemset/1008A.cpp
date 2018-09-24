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

bool isVowel(char c) {
	return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}

string s;

int main() {
	cin >> s;
	bool flag = 1;
	for (int i = 0; i < s.size(); i++) {
		if (isVowel(s[i]) || s[i] == 'n') continue;
		if (i + 1 >= s.size()) {
			flag = 0;
			break;
		}
		if (!isVowel(s[i + 1])) flag = 0;
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}
		
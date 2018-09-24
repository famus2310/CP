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


int main() {
	string s;
	cin >> s;
	int ast = s.find('*');
	string str1 = s.substr(0, ast);
	string str2 = s.substr(ast + 1, s.size() - ast);
	// cout << str1 << " " << str2 << endl;
	regex r(str1 + "(.*)" + str2);
	int q;
	scanf("%d", &q);
	while (q--) {
		string k;
		cin >> k;
		bool match = regex_match(k, r);
		if (match) cout << k << endl;
	}
	return 0;
}
		
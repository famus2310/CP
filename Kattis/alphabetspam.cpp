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
int whiteSpace, lowerCase, upperCase, symbol;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '_') whiteSpace++;
		else if (isupper(s[i])) upperCase++;
		else if (islower(s[i])) lowerCase++;
		else symbol++;
	}
	int len = s.size();
	cout.precision(6);
	cout << fixed;
	cout << (double)whiteSpace / (double)len << endl;
	cout << (double)lowerCase / (double)len << endl;
	cout << (double)upperCase / (double)len << endl;
	cout << (double)symbol / (double)len << endl;
	return 0;
}
		
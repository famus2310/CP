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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

bool isPal(const string& s) {
	int lo = 0;
	int hi = s.size() - 1;
	while (lo < hi) {
		if (s[lo] != s[hi]) return false;
		lo++; hi--;
	}
	return true;
}

set<char> character;

int main() {
	string s;
	cin >> s;
	for (char c : s) 
		character.insert(c);
	if (character.size() == 1) cout << 0 << endl;
	else if (isPal(s)) {
		cout << s.size() - 1 << endl;
	} else
		cout << s.size() << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

bool mirrorChar[35];
string s;
char arr[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

bool isPal(const string& s) {
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size() - i - 1])
			return false;
	return true;
}

bool isMirror(const string& s) {
	for (int i = 0; i < s.size(); i++) {
		if (!mirrorChar[s[i] - 'A'])
			return false;
	}
	return true;
}

int main() {
	for (int i = 0; i < 11; i++)
		mirrorChar[arr[i] - 'A'] = 1;
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		if (isMirror(s) && isPal(s))
			cout << "yes" << endl;
		else cout << "no" << endl;
	}
	NeedForSpeed;
	return 0;
}
		
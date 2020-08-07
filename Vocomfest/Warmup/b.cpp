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

char matrix[105][105];
string mode;
string met;
int n;

string snake() {
	int i = 0, j = 0;
	int up = 1;
	string ret;
	while (ret.size() < n * n) {
		char now = matrix[i][j];
		if (met[0] == 'M') {
			now = (((now - 'A') + 13) % 26 + 'A');
		}
		ret.pb(now);
		j += up;
		if (up == 1 && j == n) {
			i++;
			up = -1;
			j = n - 1;
		} else if (up == -1 && j == -1) {
			i++;
			up = 1;
			j = 0;
		}
	}
	return ret;
}

string solven() {
	string ret;
	for (int i = n - 1; i >= 0; i--) {
 		char now = matrix[i][0];
		if (met[0] == 'M') {
			now = (((now - 'A') + 13) % 26 + 'A');
		}
		ret.pb(now);
	}

	for (int i = 1; i < n; i++) {
		char now = matrix[i][i];
		if (met[0] == 'M') {
			now = (((now - 'A') + 13) % 26 + 'A');
		}
		ret.pb(now);
	}

	for (int i = n - 2; i >= 0; i--) {
		char now = matrix[i][n - 1];
		if (met[0] == 'M') {
			now = (((now - 'A') + 13) % 26 + 'A');
		}
		ret.pb(now);
	}	
	return ret;
}

string solvez() {
	string ret;
	for (int i = 0; i < n; i++) {
		char now = matrix[0][i];
		if (met[0] == 'M') {
			now = (((now - 'A') + 13) % 26 + 'A');
		}
		ret.pb(now);
	}

	for (int i = 1; i < n; i++) {
		char now = matrix[i][n - i - 1];
		if (met[0] == 'M') {
			now = (((now - 'A') + 13) % 26 + 'A');
		}
		ret.pb(now);
	}

	for (int i = 1; i < n; i++) {
		char now = matrix[n - 1][i];
		if (met[0] == 'M') {
			now = (((now - 'A') + 13) % 26 + 'A');
		}
		ret.pb(now);
	}	
	return ret;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		cin >> mode >> met;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		string ans;
		if (mode[0] == 'S')
			ans = snake();
		else if (mode[0] == 'N')
			ans = solven();
		else ans = solvez();
		cout << "Case #" << tc << ": " << ans << endl; 
	}
	return 0;
}

/*
3
5
SNAKE STANDARD
JANGA
GREPN
IDISI
JASIN
AHMMM
3
N MIRROR
PKR
BBS
IPZ
4
Z STANDARD
KAMU
BXMW
KAXC
UAPA
*/
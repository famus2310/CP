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
string s;
string cand;

bool check(char x, char y) {
	return x == '?' || x == y;
}

int main() {
	fastio;
	int n;
	cin >> n >> s;
	cand = s;
	if (n & 1) {
		cout << ":(" << endl;
		return 0;
	}
	if (n == 2) {
		if (s == "((" || s == "))" || s == ")(")
			cout << ":(" << endl;
		else cout << "()" << endl;
		return 0;
	}
	if (!check(s[0], '(') || !check(s[1], '(') || !check(s[n - 2], ')') || !check(s[n - 1], ')')) {
		cout << ":(" << endl;
		return 0;
	}
	cand[0] = cand[1] = '(';
	cand[n - 2] = cand[n - 1] = ')';
	int i = 2;
	int j = n - 3;
	int now = 2;
	int now2 = 2;
	bool ans = 1;
	while (i < j) {
		if (check(s[i], '(') && check(s[j], ')')) {
			now++;
			now2++;
			cand[i] = '(';
			cand[j] = ')';
		} else if (check(s[i], '(') && s[j] == '(') {
			cand[j] = '(';
			cand[i] = '(';
			now++;
			now2--;
		} else if (check(s[j], ')') && s[i] == ')') {
			cand[j] = ')';
			cand[i] = ')';
			now--;
			now2++;
		} else {
			cand[i] = ')';
			cand[j] = '(';
			now--;
			now2--;
		}
		// cout << now << " " << now2 << endl;
		// cout << cand << endl;
		if (now <= 0 || now2 <= 0)
			ans = 0;
		i++;
		j--;
	}
	if (now < now2) {
		while (i < s.size() && now < now2) {
			if (s[i] == '?') {
				now++;
				now2--;
				cand[i] = '(';
			}
			i++;
		}
	}
	// cout << cand << endl;
	if (now2 < now) {
		while (j >= 0 && now2 < now) {
			if (s[j] == '?') {
				now--;
				now2++;
				cand[j] = ')';
			}
			j--;
			// cout << now << " " << now2 << endl;
		}
	}
	// cout << cand << endl;
	if (now != now2)
		ans = 0;
	if (ans)
		cout << cand << endl;
	else cout << ":(" << endl;
	return 0;

}

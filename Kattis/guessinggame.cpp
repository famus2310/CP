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

const int NMAX = 1e5 + 5;


int main() {
	int guess;
	while (cin >> guess, guess != 0) {
		cin.ignore();;
		int hi = 11;
		int lo = 0;
		string s;
		getline(cin, s);
		if (s[4] == 'h') {
			hi = guess - 1;
		} else if (s[4] == 'l') {
			lo = guess + 1;
		} else if (s[0] == 'r') {
			cout << "Stan may be honest" << endl;
			continue;
		}
		bool honest = 1;
		while (cin >> guess) {
			cin.ignore();
			getline(cin, s);
			if (s[4] == 'h') {
				if (guess > hi) continue;
				if (guess > lo) hi = guess - 1;
				else {
					honest = 0;
				}
			} else if (s[4] == 'l') {
				if (guess < lo) continue;
				if (guess < hi) lo = guess + 1;
				else {
					honest = 0;
				}
			} else if (s[0] == 'r') {
				if (guess < lo || guess > hi) honest = 0;
				break;
			}
		}
		if (honest) cout << "Stan may be honest" << endl;
		else cout << "Stan is dishonest" << endl;
	}
	return 0;
}
		
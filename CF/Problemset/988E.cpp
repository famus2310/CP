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
	cin >> s;
	LL zero = 0, five = 0, two = 0, seven = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') zero++;
		if (s[i] == '5') five++;
		if (s[i] == '2') two++;
		if (s[i] == '7') seven++;
	}
	int len = s.size();
	reverse(s.begin(), s.end());
	string rev = s;
	LL mn = INF;
	if (zero > 0 && five > 0) {
		LL idx5 = -1, idx0 = -1, step = 0;
		for (int i = 0; i < rev.size(); i++) {
			if (rev[i] == '0') {
				idx0 = i;
				break;
			}
		}
		while (idx0 != 0) {
			swap(rev[idx0], rev[idx0 - 1]);
			idx0--;
			step++;
		} 
		for (int i = 0; i < rev.size(); i++) {
			if (rev[i] == '5') {
				idx5 = i;
				break;
			}
		}
		while (idx5 != 1) {
			swap(rev[idx5], rev[idx5 - 1]);
			idx5--;
			step++;
		}
		LL now = rev.size() - 1;
		while (now >= 0 && rev[now] == '0') {
			now--;
			step++;
		}
		if (now > 1 || (now == 1 && rev[now] != '0')) mn = min(mn, step);
	}
	rev = s;
	if (zero > 1) {
		LL idx1, idx2, step = 0;
		for (int i = 0; i < rev.size(); i++) {
			if (rev[i] == '0') {
				idx1 = i;
				break;
			}
		}
		while (idx1 != 0) {
			swap(rev[idx1], rev[idx1 - 1]);
			idx1--;
			step++;
		}
		for (int i = 0; i < rev.size(); i++) {
			if (rev[i] == '0' && i != idx1) {
				idx2 = i;
				break;
			}
		}
		while (idx2 != 1) {
			swap(rev[idx2], rev[idx2 - 1]);
			idx2--;
			step++;
		}
		LL now = rev.size() - 1;
		while (now >= 0 && rev[now] == '0') {
			now--;
			step++;
		}
		if (now > 1 || (now == 1 && rev[now] != '0')) mn = min(mn, step);
	}
	rev = s;
	if (five > 0 && two > 0) {
		LL idx5 = -1, idx2 = -1, step = 0;
		for (int i = 0; i < rev.size(); i++) {
			if (rev[i] == '5') {
				idx5 = i;
				break;
			}
		}
		while (idx5 != 0) {
			swap(rev[idx5], rev[idx5 - 1]);
			idx5--;
			step++;
		} 
		for (int i = 0; i < rev.size(); i++) {
			if (rev[i] == '2') {
				idx2 = i;
				break;
			}
		}
		while (idx2 != 1) {
			swap(rev[idx2], rev[idx2 - 1]);
			idx2--;
			step++;
		}
		LL now = rev.size() - 1;
		while (now >= 0 && rev[now] == '0') {
			now--;
			step++;
		}
		if (now > 1 || (now == 1 && rev[now] != '0')) mn = min(mn, step);
	}
	rev = s;
	if (five > 0 && seven > 0) {
		LL idx5 = -1, idx7 = -1, step = 0;
		for (int i = 0; i < rev.size(); i++) {
			if (rev[i] == '5') {
				idx5 = i;
				break;
			}
		}
		while (idx5 != 0) {
			swap(rev[idx5], rev[idx5 - 1]);
			idx5--;
			step++;
		} 
		for (int i = 0; i < rev.size(); i++) {
			if (rev[i] == '7') {
				idx7 = i;
				break;
			}
		}
		while (idx7 != 1) {
			swap(rev[idx7], rev[idx7 - 1]);
			idx7--;
			step++;
		}
		LL now = rev.size() - 1;
		while (now >= 0 && rev[now] == '0') {
			now--;
			step++;
		}
		if (now > 1 || (now == 1 && rev[now] != '0')) mn = min(mn, step);
	}
	if (mn == INF) mn = -1;
	cout << mn << endl;
	return 0;
}
		
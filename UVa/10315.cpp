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

char suit[] = {'C', 'D', 'H', 'S'};
char num[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
map<string, int> mp;
int white[10], black[10];

void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			string s;
			s.pb(num[j]); s.pb(suit[i]);
			mp[s] = i * 13 + j;
		}
	}
}

int isStraightFlush() {
	bool w = 1, b = 1;
	for (int i = 1; i < 5; i++) {
		if (white[i] != white[i - 1] + 1) w = 0;
		if (black[i] != black[i - 1] + 1) b = 0;
	}
	if (white[0] / 13 != white[4] / 13) w = 0;
	if (black[0] / 13 != black[4] / 13) b = 0;
	if (b && w) {
		if (white[4] % 13 == black[4] % 13) return 3;
		else if (white[4] % 13 > black[4] % 13) return 1;
		else return 2;
	} else if (b) 
		return 2;
	else if (w)
		return 1;
	return 0;
}

int isFour() {
	int cntb[15], cntw[15];
	memset(cntb, 0, sizeof cntb);
	memset(cntw, 0, sizeof cntw);
	int b = -1, w = -1;
	for (int i = 0; i < 5; i++) {
		cntb[black[i] % 13]++;
		cntw[white[i] % 13]++;
	}
	for (int i = 0; i < 13; i++) {
		if (cntw[i] == 4)
			w = i;
		if (cntb[i] == 4)
			b = i;
	}
	if (b == -1 && w == -1) return 0;
	if (b == w) return 3;
	if (b > w) return 2;
	return 1;
}

int isFullHouse() {
	int cntb[15], cntw[15];
	memset(cntb, 0, sizeof cntb);
	memset(cntw, 0, sizeof cntw);
	int twoa = -1, twob = -1, threea = -1, threeb = -1;
	for (int i = 0; i < 5; i++) {
		cntb[black[i] % 13]++;
		cntw[white[i] % 13]++;
	}
	for (int i = 0; i < 13; i++) {
		if (cntb[i] == 2) twoa = i;
		if (cntw[i] == 2) twob = i;
		if (cntb[i] == 3) threea = i;
		if (cntw[i] == 3) threeb = i;
	}
	bool b = 1, w = 1;
	// cout << threea << " " << twoa << " " << threeb << " " << twob << endl;
	if (threea == -1 || twoa == -1) b = 0;
	if (threeb == -1 || twob == -1) w = 0;
	if (!w && !b) return 0;
	if (w && b) {
		if (threeb == threea) return 3;
		if (threea > threeb) return 2;
		return 1;
	} else if (w) return 1;
	return 2;
}

int isFlush() {
	bool b = 1, w = 1;
	int cntb[15], cntw[15];
	memset(cntb, 0, sizeof cntb);
	memset(cntw, 0, sizeof cntw);
	cntb[black[0] % 13]++;
	cntw[white[0] % 13]++;
	for (int i = 1; i < 5; i++) {
		if (black[i] / 13 != black[i - 1] / 13) b = 0;
		if (white[i] / 13 != white[i - 1] / 13) w = 0;
		cntb[black[i] % 13]++;
		cntw[white[i] % 13]++;
	}
	if (!b && !w) return 0;
	if (b && w) {
		for (int i = 12; i >= 0; i--) {
			if (cntb[i] > cntw[i]) return 2;
			if (cntw[i] > cntb[i]) return 1;
		}
		return 3;
	} else if (b) return 2;
	return 1;
}

int isStraight() {
	bool b = 1, w = 1;
	int cntb[15], cntw[15];
	memset(cntb, 0, sizeof cntb);
	memset(cntw, 0, sizeof cntw);
	int mxb = -1, mxw = -1;
	for (int i = 1; i < 5; i++) {
		cntb[black[i] % 13]++;
		cntw[white[i] % 13]++;
		mxb = max(mxb, black[i] % 13);
		mxw = max(mxw, white[i] % 13);
	}
	if (mxw < 4) w = 0;
	if (mxb < 4) b = 0;
	if (w == 0 && b == 0) return 0;
	for (int i = mxw; i > mxw - 5; i--) {
		if (cntw[i] == 0) w = 0; 
	}
	for (int i = mxb; i > mxb - 5; i--) {
		if (cntb[i] == 0) b = 0;
	}
	if (!b && !w) return 0;
	else if (mxw == mxb) return 3;
	else if (mxw > mxb) return 1;
	return 2;
}

int isThree() {
	int cntb[15], cntw[15];
	memset(cntb, 0, sizeof cntb);
	memset(cntw, 0, sizeof cntw);
	int b = -1, w = -1;
	for (int i = 0; i < 5; i++) {
		cntb[black[i] % 13]++;
		cntw[white[i] % 13]++;
	}
	for (int i = 0; i < 13; i++) {
		if (cntb[i] == 3) b = i;
		if (cntw[i] == 3) w = i;
	}
	if (b == -1 && w == -1) return 0;
	if (b == w) return 3;
	if (b > w) return 2;
	return 1;
}

int isTwoPairs() {
	int cntb[15], cntw[15];
	memset(cntb, 0, sizeof cntb);
	memset(cntw, 0, sizeof cntw);
	int b1 = -1, w1 = -1, b2 = -1, w2 = -1;
	for (int i = 0; i < 5; i++) {
		cntb[black[i] % 13]++;
		cntw[white[i] % 13]++;
	}
	for (int i = 0; i < 13; i++) {
		if (cntw[i] == 2) {
			if (w1 == -1) w1 = i;
			else w2 = i;
		}
		if (cntb[i] == 2) {
			if (b1 == -1) b1 = i;
			else b2 = i;
		}
	}
	if (b1 < b2) swap(b1, b2);
	if (w1 < w2) swap(w1, w2);
	bool b = 1, w = 1;
	if (b1 == -1 || b2 == -1) b = 0;
	if (w1 == -1 || w2 == -1) w = 0;
	if (!b && !w) return 0;
	if (b && w) {
		if (b1 == w1) {
			cntb[b1]--;
			cntw[w1]--;
			if (b2 == w2) {
				cntb[b2]--;
				cntw[w2]--;
				for (int i = 12; i >= 0; i--) {
					if (cntb[i] > cntw[i]) return 2;
					if (cntw[i] > cntb[i]) return 1;
				}
				return 3;
			} else if (b2 > w2) return 2;
			return 1;
		} else if (b1 > w1) return 2;
		return 1;
	} else if (b) return 2;
	return 1;
}

int isPair() {
	int b = -1, w = -1;
	int cntb[15], cntw[15];
	memset(cntb, 0, sizeof cntb);
	memset(cntw, 0, sizeof cntw);
	for (int i = 0; i < 5; i++) {
		cntb[black[i] % 13]++;
		cntw[white[i] % 13]++;
	}
	for (int i = 0; i < 13; i++) {
		if (cntb[i] == 2) b = i;
		if (cntw[i] == 2) w = i;
	}
	if (w == -1 && b == -1) return 0;
	else if (b == w) {
		cntb[b]--;
		cntw[w]--;
		for (int i = 12; i >= 0; i--) {
			if (cntb[i] > cntw[i]) return 2;
			if (cntw[i] > cntb[i]) return 1;
		}
		return 3;
	} else if (b > w) return 2;
	return 1;
}

int isHigh() {
	int cntb[15], cntw[15];
	memset(cntb, 0, sizeof cntb);
	memset(cntw, 0, sizeof cntw);
	for (int i = 0; i < 5; i++) {
		cntb[black[i] % 13]++;
		cntw[white[i] % 13]++;
	}
	for (int i = 12; i >= 0; i--) {
		if (cntb[i] > cntw[i]) return 2;
		if (cntw[i] > cntb[i]) return 1;
	}
	return 3;
}

void solve() {
	int a, b;
	int winner = 0; // 1 = w, 2 = b, 3 = tie;
	winner = isStraightFlush();
	if (!winner) {
		// debug(1);
		winner = isFour();
	}
	if (!winner) {
		// debug(2);
		winner = isFullHouse();
	}
	if (!winner) {
		// debug(3);
		winner = isFlush();
	}
	if (!winner) {
		// debug(4);
		winner = isStraight();
	}
	if (!winner) {
		// debug(5);
		winner = isThree();
	}
	if (!winner) {
		// debug(6);
		winner = isTwoPairs();
	}
	if (!winner) {
		// debug(7);
		winner = isPair();
	}
	if (!winner) {
		// debug(8);
		winner = isHigh();
	}
	if (winner == 1) cout << "White wins." << endl;
	else if (winner == 2) cout << "Black wins." << endl;
	else cout << "Tie." << endl;
}

int main() {
	init();
	string s;
	// int tc = 1;
	while (cin >> s) {
		black[0] = mp[s];
		for (int i = 1; i < 5; i++) {
			cin >> s;
			black[i] = mp[s];
		}
		for (int i = 0; i < 5; i++) {
			cin >> s;
			white[i] = mp[s];
		}
		sort(black, black + 5);
		sort(white, white + 5);
		// cout << tc << endl;
		// tc++;
		solve();
	}
	return 0;
}
		
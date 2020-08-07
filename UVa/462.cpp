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

char suit[] = {'S', 'H', 'D', 'C'};
char num[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
int countSuit[5];
int countNum[15];
int hand[15];
bool isStopped;
int score = 0;
int noTrump = 0;
map<string, int> mp;

void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			string s;
			s.pb(num[j]);
			s.pb(suit[i]);
			// debug(s);
			mp[s] = i * 13 + j;
		}
	}
	score = 0;
	noTrump = 0;
	isStopped = false;
	memset(countNum, 0, sizeof countNum);
	memset(countSuit, 0, sizeof countSuit);
}

void solve() {
	bool temp_suit[5];
	memset(temp_suit, 0, sizeof temp_suit);
	for (int i = 0; i < 13; i++) {
		if ((hand[i] % 13) > 8) {
			score += (hand[i] % 13) - 8;
		}
		countSuit[hand[i] / 13]++;
		countNum[hand[i] % 13]++;
	}
	for (int i = 0; i < 13; i++) {
		if ((hand[i] % 13) > 8 && (hand[i] % 13) < 12) {
			if (countSuit[hand[i] / 13] < 13 - (hand[i] % 13))
				score--;
			else 
				if (hand[i] % 13 > 9)
				temp_suit[hand[i] / 13] = 1;
		}
		else if ((hand[i] % 13) == 12)
			temp_suit[hand[i] / 13] = 1;
	}
	int most_suit = 0;
	for (int i = 0; i < 4; i++) {
		if (countSuit[i] == 0 || countSuit[i] == 1)
			noTrump += 2;
		else if (countSuit[i] == 2)
			noTrump++; 
		if (countSuit[most_suit] < countSuit[i]) {
			most_suit = i;
		}
	}
	isStopped = temp_suit[0] && temp_suit[1] && temp_suit[2] && temp_suit[3];
	if (isStopped && score >= 16)
		puts("BID NO-TRUMP");
	else if (score + noTrump >= 14) 
		printf("BID %c\n", suit[most_suit]);
	else 
		puts("PASS");
}

string inp;

int main() {
	while (cin >> inp) {
		init();
		hand[0] = mp[inp];
		// cout << hand[0] << " ";
		for (int i = 1; i < 13; i++) {
			cin >> inp;
			hand[i] = mp[inp];
			// cout << hand[i] << " ";
		}
		solve();
	}
	return 0;
}
		
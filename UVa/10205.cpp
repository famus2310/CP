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

int shuff[105][55];
int ans[55];
int tmp[55];
string suit[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
string num[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
map<int, string> mp;

void solve(int n) {
	for (int i = 1; i <= 52; i++) 
		tmp[i] = ans[shuff[n][i]];
	for (int i = 1; i <= 52; i++)
		ans[i] = tmp[i];
}

void printAns() {
	for (int i = 1; i <= 52; i++) {
		cout << mp[ans[i]] << endl;
	}
}

void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			mp[i * 13 + j + 1] = num[j] + " of " + suit[i];
			// debug(mp[i * 13 + j + 1]);
		}
	}
}


int main() {
	init();
	int t;
	string s;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		if (tc != 1) puts("");
		for (int i = 1; i <= 52; i++)
			ans[i] = i;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 52 * n; i++) {
			scanf("%d", &shuff[i / 52 + 1][i % 52 + 1]);
		}
		cin.ignore();
		while (getline(cin, s), !s.empty()) {
			int k = stoi(s);
			// debug(k);
			solve(k);
		}
		printAns();
	}
	return 0;
}
		
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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


int main() {
	int round;
	while (scanf("%d", &round), round != -1) {
		string s, guess;
		cin >> s >> guess;
		int error = 0;
		bool vis[35], pressed[35];
		SET(vis, 0);
		SET(pressed, 0);
		int letters = 0;
		for (char c : s) {
			if (!vis[c - 'a']) letters++;
			vis[c - 'a'] = 1;
		}
		int guessed = 0;
		for (int i = 0; i < guess.size(); i++) {
			if (pressed[guess[i] - 'a']) continue;
			pressed[guess[i] - 'a'] = 1;
			if (vis[guess[i] - 'a'] == 0) error++;
			else guessed++;
			if (error == 7 || guessed == letters) break;
		}
		printf("Round %d\n", round);
		if (error == 7) puts("You lose.");
		else if (guessed == letters) puts("You win.");
		else puts("You chickened out.");
	}
	return 0;
}
		
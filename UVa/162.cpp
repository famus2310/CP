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

map<string, int> cards;
char sym[] = {'H', 'D', 'S', 'C'};
char num[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
deque<int> dq[3];

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			string s;
			s.pb(sym[i]);
			s.pb(num[j]);
			cards[s] = (j) + (i) * 13;
		}
	}
	string s;
	while (cin >> s, s[0] != '#') {
		dq[0].push_front(cards[s]);
		int now = 1;
		for (int i = 0; i < 51; i++) {
			cin >> s;
			dq[now % 2].push_front(cards[s]);
			now++;
		}
		now = 0;
		int winner = 0;
		while (true) {
			// cout << dq[0].size() << " " << dq[1].size() << " " << dq[2].size() << endl;
			if (dq[now % 2].empty()) {
				break;
			}
			int faceup = dq[now % 2].front(); dq[now % 2].pop_front();
			dq[2].push_back(faceup);
			// debug(faceup);
			if (faceup % 13 > 8) {
				int turn = (faceup % 13) - 8;
				now++;
				if (dq[now % 2].empty()) break;
				while (!dq[now % 2].empty() && turn > 0) {
					int tp = dq[now % 2].front(); dq[now % 2].pop_front();
					dq[2].push_back(tp);
					// debug(tp);
					turn--;
					if (tp % 13 > 8) {
						turn = (tp % 13) - 8;
						now++;
					}
				}
				if (turn != 0) break;
				// if (dq[now % 2].empty()) break;
				now++;
				while (turn == 0 && !dq[2].empty()) {
					int tp = dq[2].front(); dq[2].pop_front();
					dq[now % 2].push_back(tp);
				}
				now++;
			}
			now++;
		}
		if (dq[0].empty()) {
			cout << 1 << " " << right << setw(2) << setfill(' ') << dq[1].size() << endl;
		} else 
			cout << 2 << " " << right << setw(2) << setfill(' ') << dq[0].size() << endl;
		dq[0].clear();
		dq[1].clear();
		dq[2].clear();
	}
	return 0;
}
		
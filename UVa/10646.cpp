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

deque<int> dq, tmp;
char suit[] = {'H', 'S', 'D', 'C'};
char num[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'}; 
map<string, int> mp;

void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			string s;
			s.pb(num[j]); s.pb(suit[i]);
			mp[s] = i * 13 + j;
		}
	}
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		dq.clear();
		tmp.clear();
		for (int i = 0; i < 27; i++) {
			string s;
			cin >> s;
			dq.push_front(mp[s]);
		}
		for (int i = 0; i < 25; i++) {
			string s;
			cin >> s;
			tmp.push_front(mp[s]);
		}
		int y = 0;
		for (int i = 0; i < 3; i++) {
			int now = dq.front(); dq.pop_front();
			int x;
			if (now % 13 > 7) x = 10;
			else x = (	now % 13) + 2;
			y += x;
			int drop = 10 - x;
			for (int i = 0; i < drop; i++) {
				dq.pop_front();
			}
		}
		int now;
		while (y > 0 && !dq.empty()) {
			now = dq.back(); dq.pop_back();
			y--;
		}
		while (y > 0 && !tmp.empty()) {
			now = tmp.back(); tmp.pop_back();
			y--;
		}
		cout << "Case " << tc << ": " << num[now % 13] << suit[now / 13] << endl;
	}
	return 0;
}
		
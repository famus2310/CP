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

char dir[] = {'S', 'W', 'N', 'E'};
char suit[] = {'C', 'D', 'S', 'H'};
char num[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
map<string, int>  mp;
vector<int> hand[5];

void init() {
	mp["S"] = 0;
	mp["W"] = 1;
	mp["N"] = 2;
	mp["E"] = 3;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			string s;
			s.pb(suit[i]);
			s.pb(num[j]);
			mp[s] = i * 13 + j;
		}
	}
}

int main() {
	init();
	string now;
	while (cin >> now, now[0] != '#') {
		for (int i = 0; i < 4; i++)
			hand[i].clear();
		int play = mp[now];
		play++;
		string s;
		for (int i = 0; i < 2; i++) {
			cin >> s;
			for (int j = 0; j < s.size() - 1; j += 2) {
				string tmp = s.substr(j, 2);
				hand[play % 4].pb(mp[tmp]);
				// debug(tmp);
				play++;
			}
		}
		for (int i = 0; i < 4; i++) {
			sort(all(hand[i]));
			cout << dir[i] << ":";
			for (int it : hand[i]) 
				cout << " " << suit[it / 13] << num[it % 13]; 
			cout << endl;
		}
	}
	return 0;
}
		
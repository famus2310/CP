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

string num[] = {"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "knight", "queen", "king"};
string suit[] = {"spades", "hearts", "diamonds", "clubs"};
string trump[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
									"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty-one"};
map<string, int> mp;
double oudlers[] = {56, 51, 41, 36};


void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 14; j++) {
			string s = num[j] + " of " + suit[i];
			mp[s] = i * 14 + j;
			// debug(s);
		}
	}
	for (int i = 56; i < 77; i++) {
		string s = trump[i - 56] + " of trumps";
		mp[s] = i;
	}
	mp["fool"] = 77;
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		if (tc != 1) puts("");
		int n;
		scanf("%d", &n);
		cin.ignore();
		int req = 0;
		double score = 0;
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			if (mp[s] == 77 || mp[s] == 76 || mp[s] == 56) {
				req++;
				score += 4.5;
			} else if (mp[s] < 56 && mp[s] % 14 == 13)
				score += 4.5;
			else if (mp[s] < 56	&& mp[s] % 14 == 12)
				score += 3.5;
			else if (mp[s] < 56 && mp[s] % 14 == 11) 
				score += 2.5;
			else if (mp[s] < 56 && mp[s] % 14 == 10)
				score += 1.5;
			else 
				score += 0.5;
			// cout << s << " " << score << endl;
		} 
		double mn = oudlers[req];
		// cout << score << " " << mn << endl;
		double diff = abs(mn - score);
		printf("Hand #%d\nGame %s by %.0lf point(s).\n", tc, score >= mn ? "won" : "lost", diff);
	}
	return 0;
}
		
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

vector<char> scored;

int main() {
	string s;
	while (getline(cin, s)) {
		if (s[0] == 'G') break;
		scored.clear();
		stringstream ss(s);
		char x;
		int round = 0;
		int fi = 0;
		while (ss >> x) {
			scored.push_back(x);
		}
		int score = 0;
		for (int i = 0; i < scored.size(); i++) {
			if (isdigit(scored[i])) {
				score += scored[i] - '0';
				fi++;
				if (fi == 2) {
					fi = 0;
					round++;
				}
				if (round == 10) break;
			}
			else if (scored[i] == '/') {
				fi = 0;
				round++;
				score += (10 - (scored[i - 1] - '0'));
				if (i + 1 >= scored.size()) break;
				if (isdigit(scored[i + 1])) score += (scored[i + 1] - '0');
				else if (scored[i + 1] == 'X') score += 10;
				if (round == 10) {
					// if (isdigit(scored[i + 1])) score += (scored[i + 1] - '0');
					// else if (scored[i + 1] == 'X') score += 10;
					break; 
				}
			} else {
				fi = 0;
				round++;
				score += 10;
				if (isdigit(scored[i + 1])) score += (scored[i + 1] - '0');
				else if (scored[i + 1] == 'X') score += 10;
				if (isdigit(scored[i + 2])) score += (scored[i + 2] - '0');
				else if (scored[i + 2] == 'X') score += 10;
				else if (scored[i + 2] == '/') score += (10 - (scored[i + 1] - '0'));
				if (round == 10) {
					// if (isdigit(scored[i + 1])) score += (scored[i + 1] - '0');
					// else if (scored[i + 1] == 'X') score += 10;
					// if (isdigit(scored[i + 2])) score += (scored[i + 2] - '0');
					// else if (scored[i + 2] == 'X') score += 10;
					// else if (scored[i + 2] == '/') score += (10 - (scored[i + 1] - '0'));
					break;
				}
			}
			// cout << i <<  " " << score << endl;
		}
		cout << score << endl;
	}
	return 0;
}
/*
1 0 1 / 2 2 X 3 3 X 1 / 3 / X 1 2
1 1 13 15 17 33 36 39 59 60 72 75 92
*/
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

map<string, bool> bad;
int dp[155][2]; //prefix, flying table

int main() {
	fastio;
	int n;
	while (cin >> n && n) {	
		bad.clear();
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			bad[s] = 1;
		}
		string abbr;
		while (cin >> abbr) {
			SET(dp, 0);
			string words;
			getline(cin, words);
			words = words.substr(1, words.size() - 1);
			if (abbr == "LAST" && words == "CASE") {
				// debug("out");
				break;
			}
			stringstream ss(words);
			bool fi = 1;
			int now = 0;
			while (ss >> s) {
				if (bad[s])
					continue;
				if (fi) {
					fi = 0;
					for (int i = 0; i < s.size(); i++) {
						for (int j = abbr.size() - 1; j >= 0; j--) {
							char a = s[i];
							char b = tolower(abbr[j]);
							if (a == b) {
								if (j == 0)
									dp[j + 1][now]++;
								else
									dp[j + 1][now] += dp[j][now];
							}
						}
					}
				} else {
					for (int i = 0; i < s.size(); i++) {
						for (int j = abbr.size() - 1; j >= 0; j--) {
							if (i == 0) {
								dp[j + 1][now] = dp[j][now] = 0;
							}
							char a = s[i];
							char b = tolower(abbr[j]);
							if (a == b) {
								dp[j + 1][now] += dp[j][now] + dp[j][now ^ 1];
							}
						}
					}	
				}
				now ^= 1;
			}
			int ans = dp[abbr.size()][now ^ 1];
			if (ans > 0)
				cout << abbr << " can be formed in " << ans << " ways" << endl;
			else cout << abbr << " is not a valid abbreviation" << endl;
		}
	}
	return 0;
}
		
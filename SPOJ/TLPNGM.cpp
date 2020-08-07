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

string s;
int dp[10005];
int prefix[10005];
int tele[10005];
int idx[10005];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> s;
		int now = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0) {
				if (s[i] == '*')
					prefix[0] = 1;
				else {
					prefix[0] = 0;
					if (s[i] == '@') {
						tele[now] = i;
						idx[i] = now;
						now++;
					}
				}
				continue;
			}
			prefix[i] = prefix[i - 1];
			dp[i] = INF;
			if (s[i] == '@') {
				tele[now] = i;
				idx[i] = now;
				now++;
			}
			if (s[i] == '*') {
				prefix[i]++;
			}
		}
		now = 0;
		int lastGem = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') {
				if (i == 0) dp[i] = 0;
				else dp[i] = min(dp[i - 1] + 1, dp[i]);
			} else if (s[i] == '@') {
				if (i == 0) dp[i] = 0;
				else {
					dp[i] = dp[i - 1] + 1;
					if (now - 1 >= 0 && prefix[tele[now - 1]] == prefix[tele[now]]) {
						dp[i] = min(dp[i], dp[tele[now - 1]] + 3);
					}
					if (now - 2 >= 0 && prefix[tele[now - 2]] == prefix[tele[now]]) {
						dp[i] = min(dp[i], dp[tele[now - 2]] + 3);
					}
					if (now - 3 >= 0 && prefix[tele[now - 3]] == prefix[tele[now]]) {
						dp[i] = min(dp[i], dp[tele[now - 3]] + 3);
					}
				}
				now++;
			}  else if (s[i] == '*') {
				lastGem = i;
				dp[i] = min(dp[i - 1] + 1, dp[i]);
			}
			// debug(dp[i]);
		}
		printf("%d\n", dp[lastGem]);
	}
	return 0;
}
		
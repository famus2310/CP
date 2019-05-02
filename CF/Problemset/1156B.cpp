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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string s;
int cnt[35];
string tmp;

bool check(const string& ans) {
	for (int i = 1; i < ans.size(); i++) {
		if (abs(ans[i] - ans[i - 1]) == 1)
			return 0;
	}
	return 1;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		SET(cnt, 0);
		cin >> s;
		for (int i = 0; i < (int)s.size(); i++) {
			cnt[s[i] - 'a']++;
		}
		string ans1, ans2, ans3, ans4;
		for (int i = 0; i < 26; i+= 2) {
			for (int j = 0; j < cnt[i]; j++)
				ans1.pb((char)(i + 'a'));
		}
		for (int i = 1; i < 26; i+= 2) {
			for (int j = 0; j < cnt[i]; j++)
				ans2.pb((char)(i + 'a'));
		}
		for (int i = 25; i >= 0; i-= 2) {
			for (int j = 0; j < cnt[i]; j++)
				ans3.pb((char)(i + 'a'));
		}
		for (int i = 24; i >= 0; i-= 2) {
			for (int j = 0; j < cnt[i]; j++)
				ans4.pb((char)(i + 'a'));
		}
		// cout << ans1 << " " << ans2 << endl;
		if (check(ans1 + ans2)) {
			cout << ans1 + ans2 << endl;
		}else if (check(ans2 + ans1)) {
			cout << ans2 + ans1 << endl;
		} else if (check(ans3 + ans4)) {
			cout << ans3 + ans4 << endl;
		} else if (check(ans4 + ans3)) {
			cout << ans4 + ans3 << endl;
		}else cout << "No answer" << endl;
	}
	return 0;
}
		
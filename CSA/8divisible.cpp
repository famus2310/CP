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

vector<string> eight;
int cnt[10];

int main() {
	memset(cnt, 0, sizeof cnt);
	int now = 0;
	while (now < 1000) {
		string tmp = to_string(now);
		while (tmp.size() < 3) tmp = '0' + tmp;
		eight.pb(tmp);
		now += 8;
	}
	string s;
	cin >> s;
	if (s.size() < 4) {
		sort(all(s));
		int ans = INF;
		do {
			if (s[0] == '0') continue;
			int now = 0;
			for (int i = 0; i < s.size(); i++) {
				now = now * 10 + s[i] - '0';
			}
			if (now % 8 == 0 && now < ans) ans = now;
		} while (next_permutation(all(s)));
		if (ans == INF) ans = -1;
		cout << ans << endl;
		return 0;
	}
	string ans;
	for (int i = 0; i < 1005; i++) ans.pb('9');
	string checker = ans;
	for (int i = 0; i < s.size(); i++) cnt[s[i] - '0']++;
	for (int i = 0; i < eight.size(); i++) {
		int tmp[10], tempo[10];
		for (int j = 0; j < 10; j++) tempo[j] = cnt[j];
		memset(tmp, 0, sizeof tmp);
		for (int j = 0; j < eight[i].size(); j++) tmp[eight[i][j] - '0']++;
		bool flag = 1;
		for (int j = 0; j < 10; j++) {
			if (tmp[j] > tempo[j]) {
				flag = 0;
				break;
			} else {
				tempo[j] -= tmp[j];
			}
		}
		if (!flag) continue;
		string temp;
		for (int j = 1; j < 10; j++) if (tempo[j] != 0) {
			temp.pb(j + '0');
			tempo[j]--;
			break;
		} 
		for (int j = 0; j < 10; j++) if (tempo[j] != 0) {
			for (int k = 0; k < tempo[j]; k++) temp.pb(j + '0');
		}
		temp += eight[i];
		if (temp[0] == '0') flag = 0;
		if (flag && temp < ans) ans = temp;
	}
	if (checker == ans) ans = "-1";
	cout << ans << endl;
	return 0;
}
		
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

string s;

int main() {
	cin >> s;
	// for (int i = 1; i < s.size(); i++) {
	// 	int tmp = i;
	// 	while (tmp > 0 && abs(s[tmp] - s[tmp - 1]) == 1 && s[tmp] < s[tmp - 1]) {
	// 		swap(s[tmp], s[tmp - 1]);
	// 		tmp--;
	// 	}
	// 
	string ans;
	int cnt = 0;
	for (auto it : s) {
		if (it != '1') ans += it;
		else cnt++;
	}
	int pos = -1;
	int n = ans.size();
	while (pos + 1 < n && ans[pos + 1] == '0') ++pos;
	ans.insert(pos + 1, string(cnt, '1'));
	cout << ans << endl;
	return 0;
}
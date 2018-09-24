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
int dig;

map<string, int> mp;

int toLL(string a) {
	int ret = 0;
	for (int i = 0; i < a.size(); i++) ret = ret * 10 + a[i] - '0';
	return ret;
}

string dec(string a) {
	string b = a;
	reverse(all(b));
	int x = toLL(a);
	int y = toLL(b);
	int ret = x - y;
	return to_string(ret);
}

int main() {
	while (cin >> s >> dig) {
		mp.clear();
		if (s == "0" && dig == 0) break;
		while (s.size() != dig) s = '0' + s;
		mp[s] = 0;
		int now = 1;
		LL ans1, ans2; 
		string ansstring;
		while (true) {
			sort(all(s), greater<char>());
			s = dec(s);
			while (s.size() != dig) s = '0' + s;
			if (mp.find(s) == mp.end()) {
				mp[s] = now;
				now++;
			} else {
				ans1 = mp[s];
				ansstring = s;
				ans2 = now - mp[s];
				break;
			}
		}
		while (ansstring.size() > 1 && ansstring[0] == '0') ansstring.erase(0, 1);
		cout << ans1 << " " << ansstring << " " << ans2 << endl;
	}
	return 0;
}
		
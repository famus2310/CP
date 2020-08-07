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

const int NMAX = 1e5 + 5;

string n;
LL now;

LL stringMod(string s, LL x) {
	LL ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret = ret * 10 + s[i] - '0';
		ret %= x;
	}
	return ret;
}

string stringDiv(string a, LL b) {
	string ret;
	LL cur = 0;
	for (int i = 0; i < a.size(); i++) {
		cur *= 10;
		cur += a[i] - '0';
		if (cur < b) ret.pb('0');
		else {
			LL tmp = cur / b;
			ret.pb((char)(tmp + '0'));
			cur = cur % b;
		}
	}
	while (ret.size() > 1 && ret[0] == '0') ret.erase(0, 1);
	//debug(ret); char c; cin >> c;
	return ret;
}

int main() {
	cin >> n;
	now = 1;
	while (stringMod(n, now) == 0) {
		n = stringDiv(n, now);
		now++;
	}
	cout << now - 1 << endl;
	return 0;
}
		
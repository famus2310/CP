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

int a, b, q;

int checkOdd(string s) {
	int sz = s.size();
	int ret = 0;
	for (int i = 1; i < (1 << sz); i++) {
		if (__builtin_popcount(i) % 2 == 0)
			continue;
		string tmp;
		for (int j = 0; j < sz; j++) {
			int x = (1 << j);
			if (x & i) tmp.pb(s[j]);
		}
		bool flag = 1;
		// debug(tmp);
		for (int j = 1; j < tmp.size(); j++) {
			if (tmp[j] == tmp[j - 1]) {
				flag = 0;
				break;
			}
		}
		if (flag && tmp[0] == '1')
			ret++;
	}
	return ret;
}

int checkEven(string s) {
	int sz = s.size();
	int ret = 0;
	for (int i = 1; i < (1 << sz); i++) {
		if (__builtin_popcount(i) % 2 == 1)
			continue;
		string tmp;
		for (int j = 0; j < sz; j++) {
			int x = (1 << j);
			if (x & i) tmp.pb(s[j]);
		}
		bool flag = 1;
		for (int j = 1; j < tmp.size(); j++) {
			if (tmp[j] == tmp[j - 1]) {
				flag = 0;
				break;
			}
		}
		if (flag && tmp[0] == '1')
			ret++;
	}
	return ret;
}

void dfs(string now) {
	int x = checkOdd(now);
	int y = checkEven(now);
	// cout << now << " " << x << " " << y << endl;
	if (x == a && y == b)
		cout << now << endl;
	else if (x > a || y > b) 
		return;
	dfs(now + "0");
	dfs(now + "1");
}

int main() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++){
			// scanf("%d %d %d", &a, &b, &q);
			a = i; b = j;
			cout << i << " " << j << " : ";
			dfs("1");
		}
	}
	return 0;
}
		
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


string add(string a, string b) {
	string ret;
	if (a.size() < b.size()) swap(a, b);
	reverse(all(a));
	reverse(all(b));
	int carry = 0;
	for (int i = 0; i < b.size(); i++) {
		int x = a[i] - '0';
		int y = b[i] - '0';
		int now = x + y + carry;
		ret.pb((char)((now % 10) + '0'));
		if (now > 9) carry = 1;
		else carry = 0;
	}
	for (int i = b.size(); i < a.size(); i++) {
		int now = a[i] - '0' + carry;
		ret.pb((char)((now % 10) + '0'));
		if (now > 9) carry = 1;
		else carry = 0;
	}
	reverse(all(ret));
	return ret;
}

void solve(string a, string b) {
	if (a == b) puts("Voting Ulang");
	else if (a.size() > b.size() || (a.size() == b.size() && a > b)) 
		puts("Tere");
	else puts("Toni");
}

int main() {
	// unsigned long long x, y;
	int t;
	scanf("%d", &t);
	while (t--) {
		string x, y;
		cin >> x >> y;
		solve(x, y);
	}
	return 0;
}
		
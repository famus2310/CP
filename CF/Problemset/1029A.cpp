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
	int n, k;
	scanf("%d %d", &n, &k);
	cin >> s;
	int now = 1;
	string ans = s;
	while (now < s.size()) {
		int sz = s.size() - now;
		string a = s.substr(0, now);
		string b = s.substr(sz, now);
		if (a == b) ans = s.substr(now, s.size() - now);
		// cout << a << " " << b << endl;
		now++;
	}
	for (int i = 0; i < k - 1; i++) s += ans;
	cout << s << endl;
	return 0;
}
		
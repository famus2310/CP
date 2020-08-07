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


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		if (s.size() <= 10) cout << s << endl;
		else {
			cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
		}
	}
	return 0;
}
		
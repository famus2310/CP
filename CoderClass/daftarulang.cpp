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

map<string, int> mp;

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		mp[s] = i;
	}
	while (q--) {
		string s;
		cin >> s;
		if (mp.find(s) == mp.end()) puts("-1");
		else printf("%d\n", mp[s]);
	}
	return 0;
}
		
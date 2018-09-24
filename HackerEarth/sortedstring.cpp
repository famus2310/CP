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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int cnt[35];
string s;

bool comp(char c1, char c2) {
	if (cnt[c1 - 'a'] != cnt[c2 - 'a']) return cnt[c1 - 'a'] < cnt[c2 - 'a'];
	return c1 < c2;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(cnt, 0);
		cin >> s;
		for (char c : s) cnt[c - 'a']++;
		sort(all(s), comp);
		cout << s << endl;
	}
	return 0;
}
		
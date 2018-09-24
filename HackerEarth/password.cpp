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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

unordered_map<string, bool> mp;

int main() {
	int n;
	scanf("%d", &n);
	char ans;
	int len;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s] = 1;
		reverse(all(s));
		if (mp[s]) {
			ans = s[s.size() / 2];
			len = s.size();
		}
	}
	printf("%d %c\n", len, ans);
	return 0;
}
		
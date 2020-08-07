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

bool vis[30];
bool isAny[30][30];
string s;

int main() {
	fastio;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char now = s[i];
		for (int j = 0; j < 26; j++) {
			if (vis[j])
				isAny[j][s[i] - 'A'] = 1;
		}	
		vis[s[i] - 'A'] = 1;
	}
	int q;
	cin >> q;
	while (q--) {
		char a, b;
		cin >> a >> b;
		if (isAny[a - 'A'][b - 'A']) puts("YA");
		else puts("TIDAK");
	}
	return 0;
}
		
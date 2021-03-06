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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		int lastleft = -1;
		int lastright = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '<')
				lastleft = i;
			if (s[i] == '>' && lastright == -1)
				lastright = i;
		}
		int mn = INF;
		if (lastright != -1)
			mn = min(mn, lastright);
		if (lastleft != -1)
			mn = min(mn, n - 1 - lastleft);
		printf("%d\n", mn);
	}	
	return 0;
}
		
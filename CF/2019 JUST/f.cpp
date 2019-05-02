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

string s;

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		bool ans = 1;
		int words = 0;
		if (!islower(s[0]))
			ans = 0;
		int lastUpper = 0;
		for (int i = 1; i < s.size(); i++) {
			if (isupper(s[i])) {
				words++;
				lastUpper = i;
			}
		}
		words++;
		if (words > 7)
			ans = 0;
		if (ans)
			puts("YES");
		else puts("NO");
	}
	return 0;
}
		
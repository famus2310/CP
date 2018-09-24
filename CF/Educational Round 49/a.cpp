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
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		cin >> s;
		bool pal = 1;
		int i = 0, j = n - 1;
		while (i < j) {
			if (s[i] == s[j]) {
				i++;
				j--;
			} else if (((s[i] + 1 - 'a') % 26 == (s[j] + 1 - 'a') % 26) || ((s[i] + 1 - 'a') % 26 == (s[j] + 25 - 'a') % 26)
								|| ((s[i] + 25 - 'a') % 26 == (s[j] + 1 - 'a') % 26) || ((s[i] + 25 - 'a') % 26 == (s[j] + 25 - 'a') % 26)) {
				i++;
				j--;
			} else {
				pal = 0;
				break;
			}
		}
		if (pal) puts("YES");
		else puts("NO");
	}
	return 0;
}
		
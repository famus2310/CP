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


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string a, b;
		cin >> a >> b;
		int key = b[0] - a[0] + (b[0] < a[0] ? 26 : 0);
		bool flag = 1;
		for (int i = 1; i < a.size(); i++) {
			int shifted = b[i] - a[i] + (b[i] < a[i] ? 26 : 0);
			if (shifted != key) {
				flag = 0;
				break;
			}
		}
		if (!flag) puts("-1");
		else printf("%d\n", key % 26);
	}
	return 0;
}
		
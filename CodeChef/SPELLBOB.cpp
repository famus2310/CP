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
		string a, b;
		cin >> a >> b;
		bool flag = 0;
		for (int i = 0; i < 8; i++) {
			string tmp;
			for (int j = 0; j < 3; j++) {
				int now = (1 << j);
				if (i & now)
					tmp += a[j];
				else 
					tmp += b[j];
			}
			sort(all(tmp));
			if (tmp == "bbo") {
				flag = 1;
				break;
			}
		}
		if (flag)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
		
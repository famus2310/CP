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
	for (int i = 0; i < t; i++) {
		if (i != 0) puts("");
		int n;
		scanf("%d", &n);
		bool flag = 1;
		int a, b;
		scanf("%d %d", &a, &b);
		int diff = abs(a - b);
		for (int i = 1; i < n; i++) {
			scanf("%d %d", &a, &b);
			if (abs(a - b) != diff)
				flag = 0;
		}
		if (flag)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
		
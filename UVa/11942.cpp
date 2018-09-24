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
	int n;
	scanf("%d", &n);
	puts("Lumberjacks:");
	for (int i = 0; i < n; i++) {
		int last, now;
		scanf("%d %d", &last, &now);
		bool isUp = now > last ? 1 : 0;
		last = now;
		bool ans = 1;
		for (int i = 2; i < 10; i++) {
			scanf("%d", &now);
			if ((now < last && isUp) || (now > last && !isUp)) 
				ans = 0;
			last = now;
		}
		if (ans)
			puts("Ordered");
		else
			puts("Unordered");
	}
	return 0;
}
		
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
	int n, b, h, w;
	while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4) {
		int now = INF;
		for (int i = 0; i < h; i++) {
			int price;
			scanf("%d", &price);
			price *= n;
			bool flag = 0;
			for (int j = 0; j < w; j++) {
				int a;
				scanf("%d", &a);
				if (a > n) 
					flag = 1;
			}
			if (flag)
				now = min(now, price);
		}
		if (now <= b)
			printf("%d\n", now);
		else
			puts("stay home");
	}
	return 0;
}
		
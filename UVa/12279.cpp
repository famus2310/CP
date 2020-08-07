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
	int tc = 1;
	while (scanf("%d", &t), t != 0) {
		//set<int> s;
		int given = 0, reason = 0;
		for (int i = 0; i < t; i++) {
			int a;
			scanf("%d", &a);
			if (a == 0)
				given++;
			else 
				reason++;
		}
		printf("Case %d: %d\n", tc++, reason - given);
	}
	return 0;
}
		
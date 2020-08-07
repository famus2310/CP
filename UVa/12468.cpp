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
	int a, b;
	while (scanf("%d %d", &a, &b) == 2, (a != -1 && b != -1)) {
		printf("%d\n", min(abs(a - b), 100 - abs(a - b)));
	}
	return 0;
}
		
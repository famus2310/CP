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

LL fibo[55];

int main() {
	fibo[0] = fibo[1] = 1;
	for (int i = 2; i < 55; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", fibo[b - a]);
	}
	return 0;
}
		
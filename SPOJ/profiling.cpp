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

LL fibo[N];
LL t, a, b;

int main() {
	fibo[0] = fibo[1] = 1;
	for (int i = 2; i < N; i++) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &a, &b);
		if (b > a) puts("0");
		else if (b == 0 && a == 0) puts("1");
		else if (b == 1 && a == 0) puts("0");
		else if (b == 1 && a == 1) puts("1");
		else {
			if (b == 0) b = 2;
			LL temp = a - b;
			printf("%lld\n", fibo[temp]);
		}
	}
	return 0;
}
		
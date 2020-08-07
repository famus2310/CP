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
const int MOD = 100;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int cek(LL num) {
	LL ret = 1LL;
	for (int i = 2; i <= num; i++) {
		bool b = false;
		for (int j = 2; j < i; j++ ) {
			if (i % j == 0) {
				b = 1;
				break;
			}
		}
		if (!b) {
			int temp = 1;
			while (num % i == 0) {
				num /= i;
				temp++;
			}
			ret *= temp;
		}
	}
	return ret & 1;
}

int main() {
	LL n;
	scanf("%lld", &n);
	int ans = 0;
	for (LL i = 1; i<= n; i++) {
		if (cek(i)) {
			ans += i % MOD; ans %= MOD;
		}
	}
	printf("%d\n", ans);
	return 0;
}
		
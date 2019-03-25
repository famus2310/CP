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

const int N = 1e6 + 5;

LL factor[N];
LL rem[N];
LL ans[N];
bool notPrime[N];

void preprocess() {
	for (LL i = 2; i < N; i++)
		rem[i] = i;
	notPrime[1] = notPrime[0] = 1;
	for (LL i = 2; i < N; i++) {
		if (!notPrime[i]) {
			factor[i] = 1;
			for (LL j = 2 * i; j < N; j += i) {
				while(rem[j] > 1 && rem[j] % i == 0) {
					factor[j]++;
					rem[j] /= i;
				}
			}
		}
	}
	ans[1] = 1;
	for (LL i = 2; i < N; i++)
		ans[i] = ans[i - 1] + (int)(factor[i] > 2);
}

int main() {
	preprocess();
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL a;
		scanf("%lld", &a);
		LL x = ans[a];
		LL g = __gcd(x, a);
		x /= g;
		a /= g;
		printf("%lld/%lld\n", x, a);

	}
	for ()
	return 0;
}
		
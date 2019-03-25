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

bool notPrime[500005];

void sieve() {
	notPrime[1] = notPrime[0] = 1;
	for (LL i = 2; i < 500005; i++) {
		if (!notPrime[i]) {
			for (LL j = i * i; j <= 500005; j += i)
				notPrime[j] = 1;
		}
	}
}

bool check(LL x) {
	LL last = x % 10;
	x /= 10;
	while (x) {
		if (x % 10 == 1 && last == 3)
			return false;
		last = x % 10;
		x = x / 10;
	}
	return true;
}

int main() {
	sieve();
	LL a, b;
	scanf("%lld %lld", &a, &b);
	int cnt = 0;
	for (LL i = a; i <= b; i++) {
		if (check(i) && !notPrime[i])
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
		
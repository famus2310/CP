#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
gp_hash_table<int, int> memo;
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
const LL two31 = 1 << 31;

const int N = 1e5 + 5;

int suspect(LL b, int t, LL u, LL n) {
	LL prod = 1;
	while (u) {
		if (u & 1)
			prod = (prod * b) % n;
		b = (b * b) % n;
		u = u / 2;
	}
	if (prod == 1) return 1;
	for (int i = 1; i <= t; i++) {
		if (prod == n - 1) return 1;
		prod = (prod * prod) % n;
	}
	return 0;
}

bool isPrime(int n) {
	if (n == 1)
		return 0;
	LL k = n - 1;
	int t = 0;
	while (!(k % 2)) {
		t++;
		k = k / 2;
	}
	if (n > 2 && n % 2 == 0) return 0;
	if (n > 3 && n % 3 == 0) return 0;
	if (n > 5 && n % 5 == 0) return 0;
	if (n > 7 && n % 7 == 0) return 0;
	if (suspect(61, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n))
		return 1;
	return 0;
} 

int nx(LL x) {
	x = (x + 1234567890) % (two31);
	return x;
}	


int main() {
	auto t = clock();
	int now = 1;
	int i = 0;
	for (; i < 33333333; i++) {
		if (is_prime(now)) {
			printf("1");
		}
		else {
			printf("0");
		}
		now = nx(now);
		// if ((double)(clock() - t) / CLOCKS_PER_SEC >= 3)
			break;
	}
	printf("\n");
	return 0;
}
		
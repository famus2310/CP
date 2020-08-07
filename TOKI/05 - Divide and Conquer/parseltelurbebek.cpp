#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e6 + 5;

LL arr[N], n, m;

LL check(LL x) {
	LL ret = 0ULL;
	for (int i = 0; i < n; i++)
		ret += x / arr[i];
	return ret;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%lld", arr + i);
	LL lowerBound, upperBound;
	LL lo = 0ULL;
	LL hi = ULLONG_MAX;
	while (lo < hi) {
		LL mid = lo + (hi - lo) / 2ULL;
		if (check(mid) >= m) hi = mid - 1;
		else lo = mid + 1;
	} 
	lowerBound = hi < 5 ? 0ULL : hi - 5;
	while (check(lowerBound) != m) lowerBound++;
	lo = 0LL;
	hi = ULLONG_MAX;
	while (lo < hi) {
		LL mid = lo + (hi - lo) / 2LL;
		if (check(mid) <= m) lo = mid + 1;
		else hi = mid - 1;
	}
	upperBound = lo > ULLONG_MAX - 5 ? ULLONG_MAX : lo + 5;
	while (check(upperBound) != m) upperBound--;
	printf("%lld\n", upperBound - lowerBound + 1);
	return 0;
}
		
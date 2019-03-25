#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

LL n, c;
LL arr[N];

inline void scanint(long long int &x) {
	register long long int c = getchar_unlocked();
	x = 0;
	long long int neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

bool solve(LL x) {
	LL now = 1;
	int last = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - last >= x) {
			now++;
			if (now == c)
				return true;
			last = arr[i];
		}
	}
	return false;
}

LL binser() {
	LL lo = 0;
	LL hi = (LL)1e9;
	while (hi - lo > 2) {
		LL mid = lo + (hi - lo) / 2;
		if (solve(mid))
			lo = mid;
		else hi = mid - 1;
	}
	if (hi < lo)
		swap(hi, lo);
	while (hi >= lo) {
		if (solve(hi))
			return hi;
		hi--;
	}
}

int main() {
	LL t;
	scanint(t);
	while (t--) {
		scanint(n);
		scanint(c);
		for (int i = 0; i < n; i++)
			scanint(arr[i]);
		sort(arr, arr + n);
		printf("%lld\n", binser());
	}
	return 0;
}
		
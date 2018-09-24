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

struct node{
	LL x1, x2;
	bool operator<(node const& other) const {
		if (x1 != other.x1)
			return x1 < other.x1;
		return x2 < other.x2;
	}
};

node arr[N];
LL n;

LL solve(LL x) {
	LL sum = 0LL;
	for (LL i = 0; i < n; i++) {
		sum += min(abs(arr[i].x1 - x), abs(arr[i].x2 - x));
	}
	return sum;
} 

int main() {
	// LL n;
	scanf("%lld", &n);
	for (LL i = 0; i < n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		arr[i] = {a, b};
	}
	sort(arr, arr + n);
	LL l = -1e9;
	LL r = 1e9;
	for (int i = 0; i < 100; i++) {
		// cout << l << " " << r << endl;
		LL lf = l + (r - l) / 3;
		LL rf = r - (r - l) / 3;
		if (solve(lf) < solve(rf))
			r = rf ;
		else
			l = lf;
	}
	LL ans = INF;
	for (LL i = l; i <= r; i++)
		ans = min(solve(i), ans);
	printf("%lld\n", ans);
	return 0;
}
		
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

struct node {
	LL st, en;
	bool operator<(const node& other) {
		return en < other.en;
	}
};

node arr[N];

multiset<LL> ms; 

int main() {
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		arr[i] = {a, b};
 	}
 	sort(arr, arr + n);
 	LL ans = (x + (arr[0].en - arr[0].st)) % MOD;
 	ms.insert(arr[0].en);
 	for (LL i = 1; i < n; i++) {
 		auto ub = ms.upper_bound(arr[i].st);
 		ans = (ans + min((arr[i].st - (*ub)) * y, x + (arr[i].st - arr[i].en) * y)) % MOD;
 	}
 	printf("%lld\n", ans);
	return 0;
}
		
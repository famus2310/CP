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
	LL st, en;
};

bool comp(node s1, node s2) {
	return s1.en < s2.en;
}

node arr[N];

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld %lld", &arr[i].st, &arr[i].en);
	sort(arr, arr + n, comp);
	LL ans = 1;
	LL now = arr[0].en;
	for (int i = 1; i < n; i++) {
		if (arr[i].st <= now) continue;
		ans++;
		now = arr[i].en;
	}
	printf("%lld\n", ans);
	return 0;
}
		
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
	LL x, y;
};

bool comp(node s1, node s2) {
	return s1.y > s2.y;
}

node arr[N];

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i].x);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i].y);
	sort(arr, arr + n, comp);
	LL now = 0;
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arr[i].x - (arr[i].y * now);
		now++;
	}
	printf("%lld\n", ans);
	return 0;
}
		
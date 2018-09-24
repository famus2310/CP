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
	return s1.st < s2.st;
}

node arr[N];
LL dp[N];
LL n;

int main() {
	scanf("%lld", &n);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		arr[i] = {a, b};
	}
	sort(arr, arr + n, comp);
	LL now = 0;
	for (int i = 1; i <= 100000; i++) {
		dp[i] = (dp[i] % MOD + dp[i - 1] % MOD) % MOD;
		while (now < n && i == arr[now].st) {
			dp[arr[now].en] = (dp[i - 1] % MOD + dp[arr[now].en] % MOD + 1) % MOD;
			now++;
		}
	}
	LL ans = 0;
	printf("%lld\n", dp[100000]);
	return 0;
}
		
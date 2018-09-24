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
	LL val, idx;
	bool operator< (node const& other) {
		return val < other.val;
	}
};

node arr[N];
LL prefix[N];

int main() {
	LL t;
	scanf("%lld", &t);
	for (LL tc = 1; tc <= t; tc++) {
		LL n;
		scanf("%lld", &n);
		for (LL i = 1; i <= n; i++) {
			LL a;
			scanf("%lld", &a);
			arr[i] = {a, i};
		}
		sort(arr + 1, arr + n + 1);
		LL mn = INF64;
		LL idmn = -1;
		prefix[0] = 0;
		for (int i = 1; i <= n; i++) {
			prefix[i] = prefix[i - 1] + arr[i].val;
		}
		for (int i = 1; i <= n; i++) {
			LL dist = arr[i].val * (i - 1) - prefix[i - 1];
			dist += prefix[n] - prefix[i] - ((n - i) * arr[i].val);
			if (dist < mn) {
				mn = dist;
				idmn = arr[i].idx;
			} else if (dist == mn && arr[i].idx < idmn)
				idmn = arr[i].idx;
		}
		printf("Case %lld: %lld\n", tc, idmn);
	}
	return 0;
}
		
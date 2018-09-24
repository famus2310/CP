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

LL n, m;

struct node{
	LL st, en;
};

bool comp(node s1, node s2) {
	if (s1.st != s2.st) return s1.st < s2.st;
	return s1.en > s2.en;
}

node arr[N];

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].st, &arr[i].en);
	}
	sort(arr, arr + n, comp);
	LL ans = 0;
	LL now = 1;
	int i = 0;
	while (i < n) {
		if (arr[i].st > now) {
			puts("-1");
			return 0;
		} else if (arr[i].en < now){
			i++;
			continue;
		}
		LL tmp = now;
		ans++;
		while (i < n && arr[i].st <= now) {
			tmp = max(tmp, arr[i].en);
			i++;
		}
		now = tmp + 1;
	}
	if (now > m) printf("%lld\n", ans);
	else puts("-1");
	return 0;
}
		
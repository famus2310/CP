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

LL n, k;

vector<LL> arr[50];
vector<LL> ans;
LL bit[50];

int main() {
	memset(bit, 0, sizeof bit);
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		ans.pb(a);
		LL now = 1;
		LL cnt = 0;
		while (now < INF + 1) {
			if (now & a) {
				arr[cnt].pb(a);
				bit[cnt]++;
			}
			cnt++;
			now = now << 1;
		}
	}
	while (ans > k) {
		if (bit[now] < k) {
			now = now >> 1;
			continue;
		} else {
			
		}
	}
	return 0;
}
		
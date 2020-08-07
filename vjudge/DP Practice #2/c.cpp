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

LL t;
LL arr[1005];

LL solve(LL n) {
	vector<LL> tail;
	tail.pb(arr[0]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > tail.back()) {
			tail.pb(arr[i]);
		} else {
			LL lb = lower_bound(all(tail), arr[i]) - tail.begin();
			tail[lb] = arr[i];
		}
	}
	return tail.size();
}

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	printf("%lld\n", solve(n));
	return 0;
}
		
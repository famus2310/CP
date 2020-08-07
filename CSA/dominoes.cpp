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

const LL N = 1e6 + 5;


LL n, k;
bool arr[N];
priority_queue<pair<LL, LL >, vector<pair<LL, LL> >, greater<pair<LL, LL> > > pq;

int main() {
	cin >> n >> k;
	LL last = N;
	for (int i = 0; i < n; i++) {
		LL a; cin >> a;
		arr[a] = 1;
		last = min(a, last);
	}
	LL st = last;
	for (int i = last + 1; i < N; i++) {
		if (arr[i]) {
			if (i - last > 1) pq.push({i - last, last});
			last = i;
		} 
	}
	while (!pq.empty() && k) {
		LL now = pq.top().second;
		LL distnow = pq.top().first;
		pq.pop();
		if (k < distnow - 1) break;
		--distnow;
		--k;
		arr[now + 1] = 1;
		if (distnow > 1) {
			pq.push({distnow, now + 1});
		}
	}
	LL ans = -1;
	last = 0;
	for (int i = st + 1; i < N; i++) {
		if (arr[i] && arr[i - 1]) {
			last++;
			ans = max(ans, last);
		} else {
			last = 0;
		}
	}
	cout << ans + k + 1<< endl;
	return 0;
}
		
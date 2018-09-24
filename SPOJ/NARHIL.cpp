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

const LL N = 1e5 + 5;

LL A[N], H[N];
LL a;
LL jump[N];
LL cnt[N];
LL BITree[N], CountTree[N];
LL n;
LL ans;

inline void scanint(long long int &x){     
	register long long int c = getchar_unlocked();
	x = 0;
	long long int neg = 0;
	for (;((c < 48 || c > 57) && c != '-');c = getchar_unlocked());
	if (c == '-') {neg = 1;c = getchar_unlocked();}
	for (;c > 47 && c < 58;c = getchar_unlocked()) {x = (x << 1) + (x << 3) + c - 48;}
	if (neg) x =- x;
}

void init() {
	memset(BITree, 0, sizeof BITree);
	memset(cnt, 0, sizeof cnt);
	memset(CountTree, 0, sizeof CountTree);
}

void update(LL idx, LL val, LL sign) {
	if (val == 0) return;
	for (; idx < N; idx += (idx & -idx)) {
		BITree[idx] += val;
		CountTree[idx] += sign;
	}
}

pair<LL, LL> getSum(LL idx) {
	LL ret = 0;
	LL c = 0;
	for (; idx > 0; idx -= (idx & -idx)) {
		ret += BITree[idx];
		c += CountTree[idx];
	}
	return {ret, c};
}

int main() {
	LL t;
	scanint(t);
	while (t--) {
		init();
		ans = INF64;
		scanint(n);
		for (LL i = 1; i <= n; i++) {
			scanint(a);
			A[i] = a;
			jump[i] = 2 * abs(A[1] - A[i]);
		}
		for (LL i = 1; i <= n; i++) {
			scanint(a);
			H[i] = a;
			if (i != n) {
				cnt[H[i]]++;
			}
		}
		for (LL i = 1; i < N; i++) {
			update(N - i, cnt[i] * i, cnt[i]);
		}
		for (LL i = 1; i < n; i++) {
			//for (int k = 1; k <= 100000; k++) cout << k << ": " << getSum(N - k).first << " " << getSum(N - k).second << endl;
			if (H[i] >= H[n] && jump[i] < ans) {
				pair<LL, LL> tmp = getSum(N - H[i] - 1);
				//cout << tmp.first << " " << tmp.second << endl;
				ans = min(ans, jump[i] + max(0LL, tmp.first - (tmp.second * H[i])));
			}
			update(N - H[i], -H[i], -1);
			//for (int k = 1; k <= 100000; k++) cout << k << ": " << getSum(N - k).first << " " << getSum(N - k).second << endl;
		}
		printf("%lld\n", ans == INF64 ? -1 : ans);
	}
	return 0;
}
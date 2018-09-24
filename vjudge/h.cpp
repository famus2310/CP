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

const int N = 1e6 + 5;

LL precomp[N];
LL oddComp[N];
vector<LL> tet, preOdd;
LL n;

void init() {
	for (int i = 0; i < N; i++) {
		precomp[i] = oddComp[i]= INF;
	}
}

int main() {
	init();
	LL now = 1;
	while (now * (now + 1) * (now + 2) / 6 < N) {
		tet.pb(now * (now + 1) * (now + 2) / 6);
		if ((now * (now + 1) * (now + 2) / 6) & 1) preOdd.pb(now * (now + 1) * (now + 2) / 6);
		now++;
	}
	precomp[0] = 0;
	oddComp[0] = 0;
	for (int i = 0; i < tet.size(); i++) {
		for (int j = tet[i]; j < N; j++) precomp[j] = min(precomp[j - tet[i]] + 1, precomp[j]);
	}
	for (int i = 0; i < preOdd.size(); i ++) {
		for (int j = preOdd[i]; j < N; j++) oddComp[j] = min(oddComp[j - preOdd[i]] + 1, oddComp[j]); 
	}
	while (scanf("%lld", &n), n != 0) {
		printf("%lld %lld\n", precomp[n], oddComp[n]);
	}
	return 0;
}
		
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

const int N = 1e6 + 5;

LL arrayDiff[N + 5];
LL cnt[N];
LL prefix[N];

LL query(LL a) {
	if (a == 0)
		return prefix[N - 1];
	else return prefix[N - 1] - prefix[a - 1];
}

int main() {
	SET(arrayDiff, 0);
	SET(cnt, 0);
	prefix[0] = 0;
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arrayDiff[a]++;
		arrayDiff[b + 1]--;
	}
	for (int i = 1; i <= n; i++) {
		arrayDiff[i] = arrayDiff[i] + arrayDiff[i - 1];
		cnt[arrayDiff[i]]++;
	}
	prefix[0] = cnt[0];
	for (int i = 1; i < N; i++)
		prefix[i] = prefix[i - 1] + cnt[i];
	int q;
	scanf("%d", &q);
	while (q--) {
		int a;
		scanf("%d", &a);
		printf("%lld\n", query(a));
	}
	return 0;
}
		
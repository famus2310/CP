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

LL n;

LL startPoint[N], endPoint[N];
LL st[N], en[N];

int main() {
	LL t = 1;
	while (cin >> n, n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> startPoint[i] >> endPoint[i];
			st[i] = startPoint[i]; en[i] = endPoint[i];
		}
		sort(st, st + n);
		sort(en, en + n);
		cout << "Case " << t << ":";
		for (int i = 0; i < n; i++) {
			LL now = 0;
			now += upper_bound(st, st + n, endPoint[i]) - st;
			now -= lower_bound(en, en + n, startPoint[i]) - en + 1	;
			cout << " " << now;
		}
		cout << endl;
		t++;
	}
	return 0;
}
		
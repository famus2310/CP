#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL n;
LL arr[5005];

int main() {
	scanf("%lld", &n);
	LL ans = 1;
	LL mx = -1;
	LL idmn, idmx;
	LL lastid = INF;
	LL mn = INF;
	for (int i = 0; i < n; i++) {
		LL a;
		int flag = 0;
		scanf("%lld", &a);
		if (a >= mx) {
			mx = a;
			idmx = i;
			if (a > mx) flag = 1;
			else flag = 2;
		}
		if (a <= mn) {
			mn = a;
			idmn = i;
			flag = 1;
			if (a < mn) flag = 1;
			else flag = 2;
		}
		if (flag == 1) {
			if (abs(idmx - idmn) < lastid) {
				lastid = abs(idmx - idmn);
			}
		} else if (flag == 2) {
			lastid = abs(idmx - idmn);
		}
	}
	printf("%lld\n", lastid + 1);
	return 0;
}
		
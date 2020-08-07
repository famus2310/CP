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

LL bit0[2];
LL bit1[2];
string s1, s2;

int main() {
	memset(bit0, 0, sizeof(bit0));
	memset(bit1, 0, sizeof(bit1));
	int n;
	scanf("%d", &n);
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++) {
		if (s1[i] == '1') {
			bit1[s2[i] - '0']++;
		} else {
			bit0[s2[i] - '0']++;
		}
	}
	LL ans = bit1[1] * bit0[0] + bit1[0] * bit0[1] + bit0[0] * bit1[0];
	printf("%lld\n", ans);
	return 0;
}

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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e6 + 5;

LL NPF[2 * N];

int main() {
	for (LL i = 1; i < 2 * N; i++)
		NPF[i] = 1;
	for (LL i = 2; i < 2 * N; i++) {
		if (NPF[i] == 1) {
			for (LL j = 2 * i; j < 2 * N; j += i)
				NPF[j]++;
		}
	}
	LL q;
	scanf("%lld", &q);
	while (q--) {
		LL x;
		scanf("%lld", &x);
		printf("%lld\n", NPF[x]);
	}
	return 0;
}
		
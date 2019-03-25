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

map<pair<int, int>, int> mp;
LL A[2 * N], B[2 * N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%lld", A + i);
	for (int i = 0; i < n; i++)
		scanf("%lld", B + i);
	int mx = 0;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == 0 && B[i] != 0)
			continue;
		if (A[i] == 0 && B[i] == 0) {
			zero++;
			continue;
		}
		LL g = __gcd(A[i], B[i]);
		A[i] /= g;
		B[i] /= g;
		mp[{-B[i], A[i]}]++;
		mx = max(mx, mp[{-B[i], A[i]}]);
	}
	printf("%d\n", mx + zero);
	return 0;
}
		
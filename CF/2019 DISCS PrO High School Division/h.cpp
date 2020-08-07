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
LL MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL comb[3005][3005];
LL arr[3005];
LL fact[3005 * 3005];
LL inv[3005 * 3005];
LL invfact[3005 * 3005];
bool vis[15];

LL binomial(LL n, LL r) {
	return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}

int main() {
	fact[0] = fact[1] = 1;
	invfact[0] = invfact[1] = 1;
	inv[0] = inv[1] = 1;
	for (LL i = 2; i < 3005 * 3005; i++) {
		fact[i] = (fact[i - 1] * i)% MOD;
		inv[i] = (inv[MOD % i]	* (MOD - (MOD / i))) % MOD;
		invfact[i] = (invfact[i - 1] * inv[i]) % MOD;
	}
	// SET(arr, 0);
	fastio;
	// for (LL i = 1; i < 20; i++) {
	// 	for (LL j = 0; j <= i; j++) {
	// 		if (j == 0)
	// 			comb[i][j] = 1LL;
	// 		else if (i == j)
	// 			comb[i][j] = 1LL;
	// 		else if (j == 1)
	// 			comb[i][j] = i;
	// 		else {
	// 			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
	// 		}
	// 		cout << comb[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// LL n;
	// cin >> n;
	// LL ans = n;
	// LL now = n - 1;
	// for (LL i = 2; i <= n; i++) {
	// 	ans = (ans + comb[n][i] * now) % MOD; 
	// 	now--;
	// 	if (now == 0)
	// 		break;
	// }

	// cout << ans << endl;
	// ans = (ans + n * (n - 1) / 2 - n + 1 + MOD) % MOD;
	// cout << ans << endl;
	// return 0;
	// LL n;
	// cin >> n;
	// LL ans = 0LL;
	// LL tmp = n;
	// n = n * (n - 1) / 2;
	// cout << n << endl;
	// int zero = 0;
	// for (LL i = 0; i < (1 << n); i++) {
	// 	// cout << i << endl;
	// 	SET(vis, 0);
	// 	int comp = 0;

	// 	if (tmp - __builtin_popcountll(i) < 0)
	// 		zero++;
	// 	arr[tmp - __builtin_popcountll(i)]++;
	// 	ans = ans + max(tmp - __builtin_popcountll(i), 1LL);
	// }
	// cout << zero << endl;
	// for (int i = 0; i <= tmp; i++) {
	// 	cout << i << " : " << arr[i] << endl;
	// }
	// cout << ans << endl;
	LL n;
	cin >> n;
	LL x = n * (n - 1) / 2;
	LL ans = 0LL;//(((fact[x] * invfact[n]) % MOD) * invfact[x - n]) % MOD;
	// cout << fact[x] << endl;
	// cout << invfact[n] << endl;
	// cout << invfact[x - n] << endl;
	// cout << ans << endl;
	for (LL i = 0; i <= x; i++) {
		LL mult = max(n - i, 1LL);
		ans = (ans + (binomial(x, i) * mult) % MOD )% MOD;
		// cout << ans << endl;
	}
	cout << ans << endl;
}
		
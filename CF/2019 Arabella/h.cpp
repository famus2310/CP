#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;
 
const int N = 1e5 + 5;
 
void solve(ll a, ll b, ll c, ll d) {
	ll ret = INF64;
	if (a > 0) ret = min(ret, a);
	if (b > 0) ret = min(ret, b);
	if (c > 0) ret = min(ret, c);
	if (d > 0) ret = min(ret, d);
	ret = max(ret, 10ll);
	cout << ret << endl;
}
 
ll solve2(ll n, ll k) {
	return (n / (2ll * k) + (ll)(n % (2ll * k) > 0ll)) * 10ll;
}
 
int main() {
	NeedForSpeed;
	ll n, k;
	cin >> n >> k;

	ll ans = 0ll;
	ll ans3 = solve2(n, k);
	if (n >= 3ll * k) {
		ans += (n / (3ll * k)) * 15ll;
		n -= (n / (3ll * k)) * 3ll * k;
	}
	ll ans4 = ans + solve2(n, k);
	ll ans2 = ans + solve2(n + 3ll * k, k) - 15ll;
	if (n)
		ans += 10ll;
	if (n > 2ll * k)
		ans += 5ll;

	solve(ans, ans2, ans3, ans4);
	return 0;
}

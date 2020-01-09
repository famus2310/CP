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

const int N = 1e6 + 5;

ll arr[N];

int main() {
	NeedForSpeed;
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ll g = 0;
	for (int i = 0; i < m; i++) {
		ll a;
		cin >> a;
		g = __gcd(a, g);
	}
	ll x = arr[0] % g;
	bool ans = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] % g != x)
			ans = 0;
	}
	if (ans)
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
		
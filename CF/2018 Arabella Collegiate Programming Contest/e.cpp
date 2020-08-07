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

ll prefix[10005];
char arr[10005];

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		prefix[0] = 0;
		ll n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			char c;
			cin >> c;
			arr[i] = c;
			prefix[i] = prefix[i - 1] + (ll)(c == 'S');
		}
		ll ans = 0ll;
		while (m--) {
			char c;
			cin >> c;
			if (c == 'W') {
				ll x;
				cin >> x;
				if (x > k)
					k = x;
				else {
					if (arr[x] == 'S') 
						ans++;		
				}
			} else {
				k = n;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
		
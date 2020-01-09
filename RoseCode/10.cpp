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

ll x[] = {1, 2, 3, 4, 5, 6};
ll y[] = {1, 2, 3, 4, 5, 6};

bool check(ll n, ll m) {
	for (int i = 1; n + i <= 6; i++) {
		if (m + i <= 6) {
			if (y[n + i - 1] == m + i)
				return false;
		} else if (m - i > 0) {
			if (y[n + i - 1] == m - i)
				return false;
		}
	}
	return true;
}

int main() {
	NeedForSpeed;
	ll ret = 0;
	do {
		bool ans = 1;
		for (int i = 0; i < 6; i++) {
			ans &= check(x[i], y[i]);
		}
		if (ans) {
			for (int i = 0; i < 6; i++)
				cout << y[i] << " ";
			cout << endl;
		}
		ret = ret + (int)ans;
	} while (next_permutation(y, y + 6));
	cout << ret << endl;
	return 0;
}
		
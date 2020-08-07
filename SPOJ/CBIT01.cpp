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

ll dp[N];

void precompute() {
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = 1;
		for (int j = 1; j * j <= i; j++) {
			if (dp[i - j * j] == 1) {
				dp[i] = 0;
				break;
			}
		}
	}
}

int main() {
	NeedForSpeed;
	precompute();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (dp[n] == 1)
			cout << "Lose" << endl;
		else cout << "Win" << endl;
	}
	return 0;
}
		
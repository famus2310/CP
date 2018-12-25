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

vector<int> perfect;

bool check(int n) {
	int ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret == 10;
}

void preprocess() {
	int i = 1;
	while (perfect.size() < 10005) {
		if (check(i)) {
			perfect.pb(i);
			// cout << perfect.size() << " " << i << endl;
		}
		i++;
	}
}

int main() {
	preprocess();
	int k;
	cin >> k;
	cout << perfect[k - 1] << endl;
	return 0;
}
		
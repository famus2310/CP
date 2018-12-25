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

const LL N = 10000 + 5;

unsigned long long n;

vector<unsigned long long> v;

unsigned long long d[4] = {2, 3, 5, 7};

unsigned long long isPrime(unsigned long long n) {
	for (unsigned long long i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

void precompute(unsigned long long now) {
	// debug(now);s
	if (now > N) return;
	for (int i = 0; i < 4; i++) {
		unsigned long long tmp = now;
		tmp = tmp * 10 + d[i];
		if (isPrime(tmp)) v.pb(tmp);
		precompute(tmp);
	}
}

int main() {
	freopen("output.txt", "w", stdout);
	precompute(0);
	sort(all(v));
	for (auto it : v) {
		cout << it << endl;
	}
	return 0;
}
		
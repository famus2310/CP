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

string s;
LL leftShoes[40005];
char shoes[40005];

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= 2 * n; i++)
		cin >> shoes[i];
	LL all = 0LL;
	leftShoes[0] = 0;
	for (int i = 1; i <= 2 * n; i++) {
		leftShoes[i] = leftShoes[i - 1] + (shoes[i] == ')');
	}
	LL now = 0LL;
	for (int i = 1; i <= 2 * n; i++) { 
		LL hi = min(k, 2 * n - i);
		all += hi;
		if (shoes[i] == '(') {
			now += leftShoes[i + hi] - leftShoes[i - 1];
		} 
	}
	LL g = __gcd(now, all);
	now /= g;
	all /= g;
	printf("%lld/%lld\n", now , all);
	return 0;
}
		
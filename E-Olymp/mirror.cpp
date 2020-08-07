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

bool isPrime(int x) {
	if (x == 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return false;
	return true;
}

int rev(int x) {
	int ret = 0;
	while (x) {
		ret = ret * 10 + (x % 10);
		x = x / 10;
	}
	return ret;
}

int main() {
	int a, b;
	int cnt = 0;
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) {
		int r = rev(i);
		if (isPrime(r) && isPrime(i))
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
		
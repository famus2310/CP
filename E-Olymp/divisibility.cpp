#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


int main() {
	int n;
	scanf("%d", &n);
	int odd = 0, even = 0;
	int now = 0;
	while (n) {
		if (now & 1) odd += n % 10;
		else even += n % 10;
		n /= 10;
		now++;
	}
	printf("%d\n", odd * even);
	return 0;
}
		
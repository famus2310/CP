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

const int N = 1e6 + 5;

int cnt[N];
int mx = 0;

bool prime = 1;

void countDiv(int x) {
	int sq = sqrt(x);
	for (int i = 2; i <= sq; i++) {
		while (x % i == 0) {
			prime = 0;
			cnt[i]++;
			x /= i;
			mx = max(cnt[i], mx);
		}
	}
	if (x != 1) cnt[x]++;
}

bool isPowerOfTwo(int x) {
	return x && (!(x & (x - 1)));
}

int main() {
	memset(cnt, 0, sizeof cnt);
	int n;
	scanf("%d", &n);
	countDiv(n);
	bool step = 0;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		if (cnt[i] == 0) continue;
		ans *= i;
		if (cnt[i] != mx) {
			step = 1;
			false;
		}
	}
	printf("%d ", ans);
	if (prime) puts("0");
	else if (isPowerOfTwo(mx) && !step) {
		printf("%d\n", (int)log2(mx)); 
	} else if (isPowerOfTwo(mx) && step) {
		printf("%d\n", (int)log2(mx) + 1);
	} else {
		printf("%d\n", (int)log2(mx) + 2);
	}
	return 0;
}
		
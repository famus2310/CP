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

const int N = 1e7 + 5;

LL dp[N];

inline void scanint(int &x)
 {     register int c = getchar_unlocked();
     x = 0;
     int neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
     if(c=='-') {neg=1;c=getchar_unlocked();}
     for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
}

void preprocess() {
	dp[0] = dp[1] = 1;
	dp[2] = dp[3] = 0;
	for (LL i = 4; i < N; i++) {
		dp[i] = ((i + 1) * dp[i - 1]) % MOD; 
		dp[i] = (dp[i] - (((i - 2) * dp[i - 2]) % MOD) + MOD) % MOD; 
		dp[i] = (dp[i] - (((i - 5) * dp[i - 3]) % MOD) + MOD) % MOD;
		dp[i] = (dp[i] + (i - 3) * dp[i - 4]) % MOD;
	}
		//a(n) = (n+1)*a(n-1) - (n-2)*a(n-2) - (n-5)*a(n-3) + (n-3)*a(n-4).
}

int main() {
	preprocess();
	int t;
	scanint(t);
	while (t--) {
		int n;
		scanint(n);
		printf("%d\n", dp[n]);
	}
	return 0;
}
		
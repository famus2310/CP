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

const int N = 9999989;


bool notPrime[N];
vector<int> prime;

inline void scanint(int &x)
 {     register int c = getchar();
     x = 0;
     int neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar());
     if(c=='-') {neg=1;c=getchar();}
     for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
}

int check(int x) {
	int ret = 1;
	for (int i = 0; prime[i] <= x; i++) {
		if (x % prime[i] == 0) {
			ret = max(ret, prime[i]);
			while (x % prime[i] == 0)
				x /= prime[i];
		}
	}
	return max(ret, x);
}

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (LL i = 2; i < N; i ++) {
		if (!notPrime[i]) {
			//cout << i << endl;
			prime.pb(i);
			for (LL j = i * i; j <= N; j += i) {
				notPrime[j] = 1;
			}
		}
	}
}


int main() {
	fastio;
	sieve();
	//get_primes(9999999);
	int n;
	int x;
	int t;
	scanint(t);
	while (t--) {
		scanint(n);
		scanint(x);
		int a = max(check(x), check(x + 1));
		int b = prime[upper_bound(all(prime), x + 1) - prime.begin() - 1];
		//cout << a << " " << b << endl;
		if (a > b) {
			if (n == 1) puts("First");
			else puts("Second");
		} else if (a < b) {
			if (n == 2) puts("First");
			else puts("Second");
		} else puts("Friends");
	}
	return 0;
}
		
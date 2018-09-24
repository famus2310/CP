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

const int N = 1e6 + 5;

LL cnt[N];
LL arr[10005];

inline void scanint(long long int &x) {     
	 register long long int c = getchar();
     x = 0;
     long long int neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar());
     if(c=='-') {neg=1;c=getchar();}
     for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
 }

int main() {
	LL t;
	scanint(t);
	for (int tc = 1; tc <= t; tc++) {
		memset(cnt, 0, sizeof cnt);
		LL n;
		scanint(n);
		for (int i = 0; i < n; i++) {
			LL a;
			scanint(a);
			arr[i] = a;
			cnt[arr[i]]++;
		}
		LL ans = 0LL;
		for (int i = 0; i < n; i++) {
			LL now = 0LL;
			LL power = 1LL;
			if (arr[i] == 1) {
				if (cnt[1] > 1) ans++;
				continue;
			}
			while (power < N) {
				if (cnt[power] > 0) {
					now += cnt[power];
				}
				if (now > 1) {
					ans++;
					break;
				}
				power *= arr[i];
			}
		}
		printf("Case %d: %lld\n", tc, ans);
	}
	return 0;
}
		
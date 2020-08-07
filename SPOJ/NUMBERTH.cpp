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

const int N = 9999999;


bool notPrime[N];
unordered_map<string, int> mp;
unordered_map<string, bool> vis;

inline void scanint(int &x)
 {     register int c = getchar();
     x = 0;
     int neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar());
     if(c=='-') {neg=1;c=getchar();}
     for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
}


void sieve() {
	notPrime[0] = notPrime[1] = 1;
	mp["2"]++;
	for (LL i = 3; i < N; i += 2) {
		if (!notPrime[i]) {
			string now = to_string(i);
			sort(all(now));
			mp[now]++;
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		vis.clear();
		string s;
		cin >> s;
		int ans = 0;
		sort(all(s));
		for (int i = 0; i < (1 << s.size()); i++) {
			string tmp;
			for (int j = 0; j < s.size(); j++) {
				if (i & (1 << j))
				tmp.pb(s[j]);
			}
			if (vis[tmp]) continue;
			vis[tmp] = 1;
			ans += mp[tmp];
		}
		cout << ans << endl;
	}
	return 0;
}
		
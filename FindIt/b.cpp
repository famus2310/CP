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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;
LL comb(LL n, LL k) 
{ 
    LL res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if ( k > n - k ) 
        k = n - k; 
  
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (LL i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	int sz = 2 * n;
	string ans;
	for (int i = 0; i < sz; i++)
		ans.pb('0');

	for (int i = sz - 1; i >= 0; i--) {
		// debug(k);
		if (comb(i, n) < k) {
			k -= comb(i, n);
			n--;
			ans[i] = '1';
		}
	}
	for (int i = 0; n > 0; i++) {
		ans[i] = '1';
		n--;
	}
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}
		
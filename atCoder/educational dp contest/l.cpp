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

LL table[3005][3005];
LL arr[3005];

LL optimalStrategyOfGame(LL n) 
{ 
    // Create a table to store solutions of subproblems 
  
    // Fill table using above recursive formula. Note  
    // that the table is filled in diagonal fashion (similar 
    // to http:// goo.gl/PQqoS), from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (LL gap = 0; gap < n; ++gap) { 
        for (LL i = 0, j = gap; j < n; ++i, ++j) { 
  
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive formula 
            LL x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            LL y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            LL z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        } 
    } 
  
    return table[0][n - 1]; 
} 

int main() {
	int n;
	scanf("%d", &n);
	LL sum = 0LL;
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr + i);
		sum += arr[i];
	}
	LL ans = optimalStrategyOfGame(n);
	printf("%lld\n", ans - (sum - ans));
	return 0;
}
		
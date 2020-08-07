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

LL A[N];
LL dp[N]; //end
LL M[N][18], LL A[N];

void process2() {
  LL i, j;
  for (i = 0; i < N; i++)
      M[i][0] = i;
  for (j = 1; 1 << j <= N; j++)
      for (i = 0; i + (1 << j) - 1 < N; i++)
          if (A[M[i][j - 1]] > A[M[i + (1 << (j - 1))][j - 1]])
              M[i][j] = M[i][j - 1];
          else
              M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

LL RMQ( LL i , LL j ) {
  LL k =  log2( j - i + 1 ) ;
  if( A[M[i][k]] >  A[M[ j - (1<<k) + 1 ][k]]  )
       return  M[i][k] ;
   else return  M[ j - (1<<k) + 1 ][k] ;
}	


int main() {
	LL n, l, r;
	scanf("%lld %lld %lld", &n, &l, &r);
	for (int i = 0; i < n; i++)
		scanf("%lld", A + i);
	process2();
	SET(dp, 0);
	for (int i = 0; i < n; i++) {
		LL lo = max(i - r, 0);
		LL hi = max(0, i - l);
		if (lo == hi)
			dp[i] = 
	}
	return 0;
}
		
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
	double sum = 0;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double a;
		scanf("%lf", &a);
		if (a > 0) {
			sum += a;
			cnt++;
		}
	}
	if (sum == 0) {
		puts("Not Found");
	} else 
		printf("%.2lf\n", sum / (double) cnt);
	return 0;
}
		
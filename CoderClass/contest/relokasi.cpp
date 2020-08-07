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

int n;
double m;
int arr[N];
int sum = 0;

int main() {
	scanf("%d %lf", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
	}
	double mid = double(sum) / (double)n;
	double pivot1 = mid - (m / 2.0);
	double pivot2 = mid + (m / 2.0);
	double ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < pivot1) ans += (pivot1 - arr[i]) * (pivot1 - arr[i]);
		else if (arr[i] > pivot2) ans += (arr[i] - pivot2) * (arr[i] - pivot2);
	} 
	printf("%lf\n", ans);
	return 0;
}
		

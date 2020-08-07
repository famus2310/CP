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


void init(double* arr, int n) {
	for (int i = 0; i < n; i++)
		arr[i] = 1e9;
}

int main() {
	int n, q;
	double down, now;
	while (scanf("%d %lf %lf %d", &n, &down, &now, &q), n >= 0) {
		double arr[n + 1];
		init(arr, n);	
		while (q--) {
			int a;
			double b;
			scanf("%d %lf", &a, &b);
			arr[a] = b;
		}
		double drop = arr[0] == 1e9 ? 0 : arr[0];
		double car = (down + now) * (1.0 - drop);
		int month = 0;
		double payment = now / n;
		while (now >= car) {
			month++;
			if (arr[month] != 1e9)
				drop = arr[month];
			now -= payment;
			car = (car * (1.0 - drop));
			// debug(drop);
			// cout << now << " " << car << endl;
			// month++;
		}
		printf("%d %s\n", month, month == 1 ? "month" : "months");
	}
	return 0;
}
		
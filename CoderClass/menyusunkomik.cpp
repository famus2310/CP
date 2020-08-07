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

int arr[1005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", arr + i);
	int i = 1;
	int res = 0;
	while (i <= n) {
		while (arr[i] != i) {
			res++;
			swap(arr[i], arr[arr[i]]);
		}
		i++;
	}
	printf("%d\n", res);
	return 0;
}
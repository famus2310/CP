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

int arr[N];

int main() {
	memset(arr, 0, sizeof arr);
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int a;
		scanf("%d", &a);
		arr[a] = 1;
	}
	bool first = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			if (!first) printf(" ");
			first = 0;
			printf("%d", i);
		}
	}
	puts("");
	return 0;
}
		
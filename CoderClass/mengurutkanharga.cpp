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

int arr[105];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
				printf("%d %d\n", i + 1, j + 1);
			}
		}
	}
	return 0;
}
		
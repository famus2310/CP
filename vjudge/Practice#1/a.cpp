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

bool checker(int a) {
	string s = to_string(a);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] - '0' != s[i - 1] - '0' + 1) return false;
	}
	return true;
}

int main() {
	int n;
	int ans = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (checker(arr[i] * arr[j]) && arr[i] * arr[j] > ans) {
				ans = arr[i] * arr[j];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
		
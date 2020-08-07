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

int arr[35];
string s;

int main() {
	memset(arr, 0, sizeof arr);
	int n;
	scanf("%d", &n);
	cin >> s;
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		arr[s[i] - 'a']++;
	}
	for (int i = 0; i < n; i++) {
		if (arr[s[i] - 'a'] > 1) flag = 1;
	}
	if (n == 1) flag = 1;
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}
		
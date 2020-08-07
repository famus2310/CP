#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const LL INF64 = 1e18;

const int N = 2e5 + 5;

LL arr[N];


int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr + i);
	}
	sort(arr, arr + n);
	vector<LL> v;
	vector<LL> ans = {arr[0]};
	LL now = 1;
	for (int i = 0; i < n; i++){
		LL power = 1;	
		while (power * 2 <= INF) {
			v.clear();
			v.pb(arr[i]);
			LL lb1 = lower_bound(arr + i, arr + n, arr[i] + power) - arr;
			LL lb2 = lower_bound(arr + i, arr + n, arr[i] + power * 2) - arr;
			if (arr[lb1] == arr[i] + power) v.pb(arr[i] + power);
			if (arr[lb2] == arr[i] + power * 2) v.pb(arr[i] + power * 2);
			if (v.size() > ans.size()) ans = v;
			power = power << 1;
		}
	}
	LL len = ans.size();
	printf("%lld\n", len);
	for (int i = 0; i < ans.size(); i++){
		printf("%lld%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
		
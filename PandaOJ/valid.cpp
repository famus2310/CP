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

int cnt[300];
int n;
void dfs(int idx, int now) {
	if (now < 0) return;
	if (now == 0) {
		cnt[idx]++;
	}
	for (int i = 1; i <= 9; i++) {
		dfs(idx, now - i);
	}
}

int main() {
	for (int i = 1; i <= 30; i++) dfs(i, i);
	for (int i = 1; i <= 30; i++) {
		// cout << cnt[i] << " ";
		cout << pow(2, i - 1) - cnt[i]<< endl;
	}
	return 0;
}

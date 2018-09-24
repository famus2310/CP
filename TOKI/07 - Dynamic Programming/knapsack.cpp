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

const int NMAX = 2e3 + 5;

struct node{
	LL val, weight, idx;
};

node goods[NMAX];
LL n, m;	
LL dp[NMAX][NMAX];
vector<LL> ans;

bool comp(node n1, node n2) {
	return n1.weight < n2.weight;
}

void knapsack(int w, int n) {
	for (int i = 0; i <= n; i++)	{
		for (int j = 0; j <= w; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (goods[i - 1].weight <= j) {
				dp[i][j] = max(goods[i - 1].val + dp[i - 1][j - goods[i - 1].weight], dp[i - 1][j]);
			} else dp[i][j] = dp[i - 1][j];
		}
	}
	LL tmpw = w, tmpn = n;
	while (tmpn > 0) {
		if (dp[tmpn - 1][tmpw] == dp[tmpn][tmpw]) {
			tmpn--;
		} else {
			ans.pb(goods[tmpn - 1].idx);
			tmpw -= goods[tmpn - 1].weight;
			tmpn--;
		}
	}
	sort(all(ans));
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}




int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> goods[i].weight >> goods[i].val;
		goods[i].idx = i + 1;
	}
	sort(goods, goods + m, comp);
	knapsack(n, m);
	return 0;
}
		
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

struct node {
	int val;
	int arr[305];
	void upd(node other) {
		val = other.val;
		for (int i = 0; i < 305; i++)
			arr[i] = other.arr[i];
	}
	void init() {
		val = INF;
		for (int i = 0; i < 305; i++)
			arr[i] = 0;
	}
	void out(int x) {
		cout << val << endl;
		for (int i = 0; i < x; i++) {
			if (i > 0)
				cout << " ";
			cout << arr[i];
		}
		cout << endl;
	}
};

vector<int> a, b;
vector<int> lim;
node dp[305]; //k, isTake 
int take[305];
int tmp[305][2];

int main() {
	fastio;
	int t1, t2;
	while (cin >> t1 >> t2) {
		if (t1 == 0 && t2 == 0)
			break;
		for (int i = 0; i < 305; i++) {
			dp[i].init();
			take[i] = 0;
		}
		int n;
		cin >> n;
		int lim = 0;
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			lim += m;
			for (int j = 0; j <= 305; j++)
				take[j] = 0;
			tmp[0][0] = tmp[0][1] = 0;
			for (int k = 0; k < 2; k++) {
				for (int j = 1; j <= m; j++) {
					cin >> tmp[j][k];
				}
			}
			for (int j = 0; j <= m; j++) {
				take[j] = tmp[j][0] + tmp[m - j][1];
			}
			for (int j = lim; j >= 0; j--) {
				if (i == 0) {
					dp[j].val = take[j];
					dp[j].arr[i] = j;
				} else {
					dp[j].val = dp[j].val + take[0];
					for (int k = 1; k <= m && j - k >= 0; k++) {
						// dp[j] = min(dp[j], dp[j - k] + take[k]);
						if (dp[j].val > dp[j - k].val + take[k]) {
							dp[j].upd(dp[j - k]);
							dp[j].val += take[k];
							dp[j].arr[i] = k;
						}
					}
				}
				// cout << "take " << j << " : " << dp[j].val << endl;
			}
		}
		dp[t1].out(n);
	}
	return 0;
}
/*
10 12
5
5
10 30 70 150 310
10 20 40 60 180
7
30 60 90 120 160 200 240
20 60 100 130 160 200 240
4
40 60 80 100
30 70 100 120
3
60 120 180
20 50 90
3
30 70 100
30 70 100
0 0
*/
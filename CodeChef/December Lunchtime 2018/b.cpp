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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

double prob[1005];
int cnt[1005];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < k; j++) {
			scanf("%d", cnt + j);
			sum += cnt[j];
		}
		for (int j = 0; j < k; j++) {
			if (i == 0)
				prob[j] = (double)cnt[j] / sum;
			else {
				prob[j] = (prob[j] * (cnt[j] + 1.0) + (1.0 - prob[j]) * (cnt[j])) / (double)(sum + 1.0);
			}
		}
	}
	for (int j = 0; j < k; j++) {
		if (j != 0) cout << " ";
		cout << prob[j];
	}
	cout << endl;
	return 0;
}
		
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

int arr[105][105];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int cnt = 0;
		int i = 0;
		int j = 0;
		int now = 1;
		int inc = 0;
		while (now <= n * n) {
			arr[i][j] = now;
			now++;
			if (j == 0 || i == n - 1) {
				j = i + 1;
				if (j >= n) {
					inc++;
					j = n - 1;
				}
				i = inc;
			} 
			else {
				j--;
				i++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j != 0) cout << " ";
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
	// 0, 0 -> 0, 1 -> 1, 0 - > 0, 2 - > 1, 1,
//3, 0 -> 1, 3 -> 2, 2 -> 3, 1 -> 2, 3 -> 3, 2 - > 3, 3
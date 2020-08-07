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

int n;
int arr[3 * N];
int cnt[3];

int main() {
	SET(cnt, 0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		arr[i] = c - '0';
		cnt[c - '0']++;
	}
	int bal = n / 3;
	if (cnt[0] < bal) {
		for (int i = 0; i < n && cnt[0] < bal; i++) {
			if (arr[i] != 0 && cnt[arr[i]] > bal) {
				cnt[arr[i]]--;
				arr[i] = 0;
				cnt[0]++;
			}
		}
 	}
 	if (cnt[2] < bal) {
 		for (int i = n - 1; i >= 0 && cnt[2] < bal; i--) {
 			if (arr[i] != 2 && cnt[arr[i]] > bal) {
 				cnt[arr[i]]--;
 				arr[i] = 2;
 				cnt[2]++;
 			}
 		}
 	}
 	if (cnt[1] < bal) {
 		for (int i = 0; i < n && cnt[1] < bal; i++) {
 			if (arr[i] == 2 && cnt[2] > bal) {
 				cnt[2]--;
 				arr[i] = 1;
 				cnt[1]++;
 			}
 		}
 		for (int i = n - 1; i >= 0 && cnt[1] < bal; i--) {
 			if (arr[i] == 0 && cnt[0] > bal) {
 				cnt[0]--;
 				arr[i] = 1;
 				cnt[1]++;
 			}
 		}
 	}
 	for (int i = 0; i < n; i++)
 		cout << arr[i];
 	cout << endl;
	return 0;
}
		
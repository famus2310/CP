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

int arr[15];

int main() {
	int n;
	cin >> n;
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	int now = 0;
	for (int i = 0; i < n; i++) {
		now += arr[i];
		if (now != total - now && now != 0 && total - now != 0) {
			cout << i + 1;
			for (int j = 1; j <= i + 1; j++)
				cout << " " << j;
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
		
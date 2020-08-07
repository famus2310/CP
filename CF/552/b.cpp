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

int arr[105];
int n;


bool check(int x) {
	bool ans1 = 1;
	int same = arr[0] - x;
	for (int i = 1; i < n; i++) {
		if (arr[i] - x != same && arr[i] + x != same && arr[i] != same)
			ans1 = 0;
	}
	bool ans2 = 1;
	same = arr[0] + x;
	for (int i = 1; i < n; i++) {
		if (arr[i] - x != same && arr[i] + x != same && arr[i] != same)
			ans2 = 0;
	}
	bool ans3 = 1;
	same = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - x != same && arr[i] + x != same && arr[i] != same)
			ans3 = 0;
	}
	return ans1 || ans2 || ans3;
}

int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int d = 0; d <= 500; d++) {
		if (check(d)) {
			cout << d << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
		
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

int arr[2 * N];
bool taken[2 * N];
vector<int> incr;
vector<int> decr;

int main() {
	int n;
	scanf("%d", &n);
	int tkcount = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (incr.empty() || incr.back() != arr[i]) {
			taken[i] = 1;
			incr.pb(arr[i]);
			tkcount++;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (taken[i])
			continue;
		if (decr.empty() || decr.back() != arr[i]) {
			tkcount++;
			decr.pb(arr[i]);
		}
	}
	if (tkcount != n)
		puts("NO");
	else {
		puts("YES");
		cout << incr.size() << endl;
		for (auto it : incr)
			cout << it << " ";
		cout << endl;
		cout << decr.size() << endl;
		for (auto it : decr)
			cout << it << " ";
		cout << endl;
 	}
	return 0;
}
		
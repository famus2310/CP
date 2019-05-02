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

int freq[2 * N];
int arr[2 * N];

int main() {
	SET(freq, 0);
	int n;
	scanf("%d", &n);
	int mxfreq = 0;
	int mx;
	int pos;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
		freq[a]++;
		if (freq[a] > mxfreq) {
			mxfreq = freq[a];
			mx = a;
			pos = i;
		}
	}
	cout << n - mxfreq << endl;
	for (int i = pos + 1; i < n; i++) {
		if (arr[i] == mx)
			continue;
		else if (arr[i] > mx) {
			cout << 2 << " " << i + 1 << " " << i << endl;
		} else {
			cout << 1 << " " << i + 1 << " " << i << endl;
		}
	}
	for (int i = pos - 1; i >= 0; i--) {
		if (arr[i] == mx)
			continue;
		else if (arr[i] > mx) {
			cout << 2 << " " << i + 1 << " " << i + 2 << endl;
		} else {
			cout << 1 << " " << i + 1 << " " << i + 2 << endl;
		}	
	}
	return 0;
}
		
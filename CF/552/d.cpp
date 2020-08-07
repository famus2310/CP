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

bool sunlight[2 * N];
int n;

int main() {
	fastio;
	int a, b;
	cin >> n >> b >> a;
	int mxa = a;
	for (int i = 0; i < n; i++)
		cin >> sunlight[i];
	int i = 0;
	while (a + b > 0 && i < n) {
		if (sunlight[i]) {
			if (a == mxa) {
				a--;
				i++;
			}
			else if (b){
				b--;
				a++;
				i++;
			} else {
				a--;
				i++;
			}
		} else {
			if (a) {
				a--;
				i++;
			} else {
				b--;
				i++;
			}
		}
		// cout << a << " " << b << endl;
	}
	cout << i << endl;
	return 0;
}
		
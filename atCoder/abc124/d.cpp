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

int n, k;
string s;

vector<pair<int, int> > consecone;
vector<pair<int, int> > conseczero;

int main() {
	fastio;
	cin >> n >> k;
	cin >> s;
	int one = 0;
	int now = 0;
	int zero = 0;
	int i = 0;
	int j = 0;
	while (i < n) {
		if (s[i] - '0' == 0) {
			while (i < n && s[i] - '0' == 0)
				i++;
			now++;
		} else {
			while (i < n && s[i] - '0' == 1)
				i++;
		}
		while (now > k && j < i) {
			if (s[j] - '0' == 0) {
				now--;
				while (s[j] - '0' == 0) {
					j++;
				}
			} else {
				while (s[j] - '0' == 1)
					j++;
			}
		}
		// cout << i << " " <<  j << endl;
		if (now <= k) 
			one = max(one, i - j);
	}
	// cout << endl;
	// now = i = j = 0;
	// while (i < n) {
	// 	if (s[i] - '0' == 1) {
	// 		while (i < n && s[i] - '0' == 1)
	// 			i++;
	// 		now++;
	// 	} else {
	// 		while (i < n && s[i] - '0' == 0)
	// 			i++;
	// 	}
	// 	while (now > k && j < i) {
	// 		if (s[j] - '0' == 1) {
	// 			now--;
	// 			while (s[j] - '0' == 1) {
	// 				j++;
	// 			}
	// 		} else {
	// 			while (s[j] - '0' == 0)
	// 				j++;
	// 		}
	// 	}
	// 	cout << i << " " << j << endl;
	// 	if (now <= k) 
	// 		zero = max(zero, i - j);
	// }
	// cout << max(zero, one) << endl;
	cout << one << endl;
	return 0;
}
		
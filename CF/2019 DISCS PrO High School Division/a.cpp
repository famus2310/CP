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

int n, m, k;

int avail[256];
int need[256];
string s;

int main() {
	SET(avail, 0);
	SET(need, 0);
	fastio;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (char c : s) 
			avail[c - 'a']++;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (char c : s) {
			need[(c - 'a' + 26 + k) % 26]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (avail[i] < need[i]) {
			cout << "It is gonna be daijoubu." << endl;
			return 0;
		}
	}
	cout << "Make her kokoro go doki-doki!" << endl;
	return 0;
}
			
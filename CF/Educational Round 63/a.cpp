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

string s;
int vis[256];

int main() {
	SET(vis, -1);
	fastio;
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int now = s[i];
		for (int j = now + 1;  j <= 'z'; j++) {
			if (vis[j] != -1) {
				cout << "YES" << endl;
				cout << vis[j] + 1 << " " << i + 1 << endl; 
				return 0;
			}
		}
		vis[now] = i;
	}
	cout << "NO" << endl;
	return 0;
}
		
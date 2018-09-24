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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string dq;
unordered_map<char, bool> vis;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (vis[c]) continue;
		if (dq.empty()) {
			dq.push_back(c);
			vis[c] = 1;
		}
		else {
			while (!dq.empty() && dq.back() <= c) {
				vis[dq.back()] = 0;
				dq.pop_back();
			}
			dq.push_back(c);
			vis[c] = 1;
		}
		// cout << dq << endl;
	}
	cout << dq << endl;
	return 0;
}
		
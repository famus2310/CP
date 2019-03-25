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

vector<int> cntl[256];
vector<int> cntr[256];
vector<int> q1, q2;

int main() {
	int n;
	scanf("%d", &n);
	int qm1 = 0;
	int qm2 = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c != '?')
			cntl[c - 'a'].pb(i + 1);
		else q1.pb(i + 1);
	}
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c != '?')
			cntr[c - 'a'].pb(i + 1);
		else q2.pb(i + 1);
	}
	vector<pair<int, int> > ans;
	for (int i = 0; i < 26; i++) {
		while (!cntl[i].empty() && !cntr[i].empty()) {
			ans.pb({cntl[i].back(), cntr[i].back()});
			cntl[i].pop_back();
			cntr[i].pop_back();
		}
		while (!cntl[i].empty() && !q2.empty()) {
			ans.pb({cntl[i].back(), q2.back()});
			cntl[i].pop_back();
			q2.pop_back();
		}
		while (!cntr[i].empty() && !q1.empty()) {
			ans.pb({q1.back(), cntr[i].back()});
			cntr[i].pop_back();
			q1.pop_back();
		}
	}
	while (!q1.empty() && !q2.empty()) {
		ans.pb({q1.back(), q2.back()});
		q1.pop_back();
		q2.pop_back();
	}
	cout << ans.size() << endl;
	for (auto it : ans) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}
		
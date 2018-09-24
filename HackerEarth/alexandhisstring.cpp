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

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
	string s;
	cin >> s;
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		pq.push(s[0]);
		s.erase(0, 1);
	}
	string x;
	while (!pq.empty()) {
		int now = pq.top(); pq.pop();
		x.pb(now);
		if (!s.empty()) {
			pq.push(s[0]);
			s.erase(0, 1);
		}
	}
	cout << x << endl;
	return 0;
}
		
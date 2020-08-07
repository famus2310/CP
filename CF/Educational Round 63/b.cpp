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

int n;
string s;
queue<int> qv, qp;

int main() {
	fastio;
	cin >> n >> s;
	int eight = 0;
	int bef = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '8')
			qp.push(i);
		else qv.push(i);
	}
	int counter = n;
	int turn = 0;
	while (counter > 11 && (!qv.empty() && !qp.empty())) {
		if (turn == 0) {
			qp.pop();
		} else {
			qv.pop();
		}
		turn = turn ^ 1;
		counter--;
	}
	if (qv.empty()) {
		cout << "YES" << endl;
	} else if (qp.empty()) {
		cout << "NO" << endl;
	} else {
		if (qp.front() < qv.front()) 
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
		
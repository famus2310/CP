#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int NMAX = 1e5 + 5;

void bfs(int n) {
	int cnt = 0;
	string tmp = "";
	queue<string> q;
	q.push(tmp);
	while (!q.empty()) {
		string now = q.front(); q.pop();
		if (now.size() == n) {
			if (now.find("11") == string::npos) {
				cout << now << endl;
				cnt++;
			}
			continue;
		}
		q.push(now + "0");
		q.push(now + "1");
	}
	cout << cnt << endl;
}

int main() {
	int n;
	cin >> n;
	bfs(n);
	return 0;
}
		
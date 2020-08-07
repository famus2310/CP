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

const int N = 1e5 + 5;

queue<string> q;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			string s;
			cin >> s;
			q.push(s);
		} else {
			cout << q.front() << endl;
			q.pop();
		}
	}
	return 0;
}
		